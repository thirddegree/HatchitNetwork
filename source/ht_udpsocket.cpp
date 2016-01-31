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

#include <ht_udpsocket.h>

namespace Hatchit {

    namespace Network {

        UDPSocket::UDPSocket(SOCKET socket)
        {
            m_socket = socket;
        }

        UDPSocket::~UDPSocket()
        {
#ifdef HT_SYS_WINDOWS
            closesocket(m_socket);
#else
            close(m_socket);
#endif
        }

        int UDPSocket::Bind(const SocketAddress& address)
        {
            int error = bind(m_socket, &address.m_sockAddr, address.GetSize());
            if(error != 0)
            {
#ifdef _DEBUG
                ReportError("UDPSocket::Bind");                
#endif
                return LastError(); 
            }

            return NO_ERROR;
        }

        int UDPSocket::SendTo(const void* data, int len, const SocketAddress& to)
        {
            int byteCount = sendto(m_socket, static_cast<const char*>(data), len, 0, &to.m_sockAddr, to.GetSize());
            if(byteCount < 0)
            {
#ifdef _DEBUG
                ReportError("UDPSocket::SendTo");
#endif
                return -LastError();
            }

            return byteCount;
        }

        int UDPSocket::ReceiveFrom(void* buffer, int len, SocketAddress& from)
        {
            socklen_t fromLen = from.GetSize();
            int byteCount = recvfrom(m_socket, static_cast<char*>(buffer), len, 0, &from.m_sockAddr, &fromLen);
            if(byteCount < 0)
            {
#ifdef _DEBUG
                ReportError("UDPSocket::ReceiveFrom");
#endif
                return -LastError();
            }

            return byteCount;
        }
    }
}
