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

#include <ht_tcpsocket.h>
#include <ht_debug.h>

namespace Hatchit {

    namespace Network {

        TCPSocket::TCPSocket()
        {
            m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if(m_socket == INVALID_SOCKET)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::TCPSocket");
#endif
            }
        }

        TCPSocket::TCPSocket(SOCKET socket)
        {
            m_socket = socket;
        }

        TCPSocket::~TCPSocket()
        {
#ifdef HT_SYS_WINDOWS
            closesocket(m_socket);
#else
            HT_DEBUG_PRINTF("Closing socket.\n");
            close(m_socket);
#endif
        }

        int TCPSocket::Connect(const SocketAddress& address)
        {
            int error = connect(m_socket, &address.m_sockAddr, static_cast<int>(address.GetSize()));
            if(error < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Connect");
#endif
                return -LastError();
            }
            m_address = address;

            return NO_ERROR;
        }


        int TCPSocket::Bind(const SocketAddress& address)
        {
            int error = bind(m_socket, &address.m_sockAddr, static_cast<int>(address.GetSize()));
            if(error != 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Bind");
#endif
                return LastError();
            }
            m_address = address;

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

        TCPSocketPtr TCPSocket::Accept()
        {
            socklen_t length = static_cast<socklen_t>(sizeof(sockaddr));
            SocketAddress _newAddress;
            SOCKET newSocket = accept(m_socket, &_newAddress.m_sockAddr, &length);
            if(newSocket == INVALID_SOCKET)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Accept");
#endif
                return nullptr;
            }
            TCPSocket* socket = new TCPSocket(newSocket);
            socket->m_address = _newAddress;

            return TCPSocketPtr(socket);
        }

        int TCPSocket::Send(const void* data, int len, int flags)
        {
            int byteCount = send(m_socket, static_cast<const char*>(data), len, flags);
            if(byteCount < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Send");
#endif
                return -LastError();
            }

            return byteCount;
        }

        int TCPSocket::Receive(void* buffer, int len, int flags)
        {
            char* charBuffer = static_cast<char*>(buffer);
            int byteCount = recv(m_socket, charBuffer, len, flags);
            if(byteCount < 0)
            {
#ifdef _DEBUG
                ReportError("TCPSocket::Receive");
#endif
                return -LastError();
            }

            //recv won't null terminate the string
            charBuffer[byteCount] = '\0';

            return byteCount;
        }

        const SocketAddress& TCPSocket::GetAddress() const
        {
            return m_address;
        }
    }
}
