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

#include <ht_tcpsocket.h>

namespace Hatchit {

    namespace Network {

        TCPSocket::TCPSocket(SOCKET socket)
        {
            m_socket = socket;
        }

        TCPSocket::~TCPSocket()
        {
#ifdef HT_SYS_WINDOWS
            closesocket(m_socket);
#else
            close(m_socket);
#endif
        }

        int TCPSocket::Connect(const SocketAddress& address)
        {
            int error = connect(m_socket, &address.m_sockAddr, (int)address.GetSize());
            if(error < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Connect");
#endif
                return -LastError();
            }

            return NO_ERROR;
        }


        int TCPSocket::Bind(const SocketAddress& address)
        {
			int error = bind(m_socket, &address.m_sockAddr, (int)address.GetSize());
            if(error != 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Bind");
#endif
                return LastError();
            }

            return NO_ERROR;
        }


        int TCPSocket::Listen(int backlog)
        {
            int error = listen(m_socket, backlog);
            if(error < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Listen");
#endif
                return -LastError();
            }

            return NO_ERROR;
        }

        TCPSocketPtr TCPSocket::Accept(SocketAddress& address)
        {
            socklen_t length = (socklen_t)address.GetSize();
            SOCKET newSocket = accept(m_socket, &address.m_sockAddr, &length);
            if(newSocket == INVALID_SOCKET)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Accept");
#endif
                return nullptr;
            }

            return TCPSocketPtr(new TCPSocket(newSocket));
        }

        int TCPSocket::Send(const void* data, int len)
        {
            int byteCount = send(m_socket, static_cast<const char*>(data), len, 0);
            if(byteCount < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Send");
#endif
                return -LastError();
            }

            return byteCount;
        }

        int TCPSocket::Receive(void* buffer, int len)
        {
            int byteCount = recv(m_socket, static_cast<char*>(buffer), len, 0);
            if(byteCount < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Receive");
#endif
                return -LastError();
            }

            return byteCount;
        }
    }
}
