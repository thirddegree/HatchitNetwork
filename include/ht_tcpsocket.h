/**
**    Hatchit Engine
**    Copyright(c) 2015 Third-Degree
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

#pragma once

#include <ht_platform.h>
#include <ht_network.h>
#include <ht_socketaddress.h>
#include <memory>

#ifndef DEF_LISTEN_BACKLOG
#define DEF_LISTEN_BACKLOG 32
#endif

namespace Hatchit {

    namespace Network {
        
        class HT_API TCPSocket
        {
        public:
            ~TCPSocket();

            int                         Connect(const SocketAddress& address);
            int                         Bind(const SocketAddress& address);
            int                         Listen(int backlog = DEF_LISTEN_BACKLOG);
            std::shared_ptr<TCPSocket>  Accept(SocketAddress& address);
            int                         Send(const void* data, int len);
            int                         Receive(void* buffer, int len);
        private:
            SOCKET m_socket;
        
            TCPSocket(SOCKET socket);

            friend class SocketUtil;
        };
        typedef std::shared_ptr<TCPSocket> TCPSocketPtr;
    }
}
