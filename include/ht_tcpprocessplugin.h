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
#include <ht_network.h>
#include <memory>

namespace Hatchit
{
    namespace Network
    {
        class SocketAddress;
        class Packet;
        class TCPInterface;

        class TCPProcessPlugin
        {
        public:
            TCPProcessPlugin();

            virtual ~TCPProcessPlugin();

            virtual void OnAttach() = 0;
            virtual void OnDetach() = 0;
            virtual void OnUpdate() = 0;
            virtual void OnReceive(std::shared_ptr<Packet>& packet) = 0;

            virtual void OnAcceptConnection(const SocketAddress& address) = 0;
            virtual void OnFailedConnection() = 0;

        private:
            std::shared_ptr<TCPInterface> m_parent;
        };
    }
}