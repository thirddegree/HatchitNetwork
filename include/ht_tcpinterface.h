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

#include <ht_platform.h>
#include <ht_tcpsocket.h>
#include <ht_threadqueue.h>
#include <thread>

namespace Hatchit
{
    namespace Network
    {
        class RemoteClient;
        class TCPProcessPlugin;

        class HT_API TCPInterface
        {
        public:
            TCPInterface();

            virtual ~TCPInterface();

            bool Init(const char* address, uint16_t port, uint32_t maxIncomingConnections, uint32_t maxConnections = 0);

            void Shutdown();

            void AttachPlugin(std::shared_ptr<TCPProcessPlugin>& plugin);
            void DetachPlugin(std::shared_ptr<TCPProcessPlugin>& plugin);

        private:
            std::thread                                             m_update;
            TCPSocketPtr                                            m_listen;
            std::vector<std::shared_ptr<TCPProcessPlugin>>          m_plugins;
            Core::ThreadsafeQueue<std::shared_ptr<RemoteClient>>    m_clients;
            uint32_t                                                m_maxConnections;
            uint32_t                                                m_maxIncomingConnections;
        };
    }
}