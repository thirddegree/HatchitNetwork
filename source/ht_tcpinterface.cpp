/**
**    Hatchit Engine
**    Copyright(c) 2015-2016 Third-Degree
**
**    GNU Lesser General Public License
**    This file may be used under the terms of the GNU Lesser
**    General Public License version 3 as published by the Free
**    Software Foundation and appearing in the file LICENSE.LGPLv3 included
**    in the packaging of this file. Please review the following information
**    to ensure the GNU Lesser General Public License requirements
**    will be met: https://www.gnu.org/licenses/lgpl.html
**
**/

#include <ht_tcpinterface.h>
#include <ht_tcpprocessplugin.h>
#include <ht_remoteclient.h>
#include <ht_debug.h>

namespace Hatchit
{
    namespace Network
    {
        TCPInterface::TCPInterface()
        {

        }

        TCPInterface::~TCPInterface()
        {

        }

        bool TCPInterface::Init(const char *address, uint16_t port, uint32_t maxIncomingConnections,
                                uint32_t maxConnections)
        {
            /**
             * First, check the max connection value
             * If the max connection is ZERO, the default. We will
             * set to whatever the max incoming connects is.
             *
             * If maxIncomingConnections is specified to be <= 0, then
             * we will set 1 incoming connection max
             */
            if(maxConnections <= 0)
                m_maxConnections = (maxIncomingConnections > 0) ? maxConnections : 1;
            if(maxIncomingConnections <=0)
                m_maxIncomingConnections = 1;

            /**
             * Create the server TCP listen socket
             */
            SocketAddress listenAddress(address, port);
            m_listen = std::make_shared<TCPSocket>();
            m_listen->Bind(listenAddress);
            m_listen->Listen();

            /**
             * Define update thread
             */
            m_update = std::thread([this](){
                while(true)
                {
                    TCPSocketPtr _newConnection = this->m_listen->Accept();
                    if(_newConnection)
                    {
                        RemoteClientPtr _client = std::make_shared<RemoteClient>();
                        _client->SetSocket(_newConnection);
                        this->m_clients.push(_client);

                        for(auto& plugin : this->m_plugins)
                            plugin->OnAcceptConnection(_newConnection->GetAddress());


                        std::string message = "Hello";
                        _newConnection->Send(message.data(), message.size());

                    }
                }
            });
            m_update.join();

            return true;
        }

        void TCPInterface::Shutdown()
        {
            /**
             * Clear all contained shared memory
             */
            m_clients.clear();
        }

        void TCPInterface::AttachPlugin(std::shared_ptr<TCPProcessPlugin> &plugin)
        {
            /**
             * Add the plugin to the interface plugin list.
             * Then we should fire off the OnAttach event of
             * the plugin.
             */
            m_plugins.push_back(plugin);
            plugin->OnAttach();
        }

        void TCPInterface::DetachPlugin(std::shared_ptr<TCPProcessPlugin> &plugin)
        {
            /**
             * TODO:
             *  Remove plugin from list.
             */
        }
    }
}