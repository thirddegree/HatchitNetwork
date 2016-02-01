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

#include <ht_socketaddress.h>
#include <algorithm>
#include <cstring>

namespace Hatchit {

    namespace Network {
       

        SocketAddress::SocketAddress(hostent* host, uint16_t port)
        {
            GetAsSockAddrIn()->sin_family = AF_INET;
            memcpy(host->h_addr, reinterpret_cast<void*>(&GetAsSockAddrIn()->sin_addr.s_addr), host->h_length);
            GetAsSockAddrIn()->sin_port = htons(port);
        }

        SocketAddress::SocketAddress(uint32_t address, uint16_t port)
        {
            GetAsSockAddrIn()->sin_family = AF_INET;
            GetIPv4Ref() = htonl(address);
            GetAsSockAddrIn()->sin_port = htons(port);      
        }

        SocketAddress::SocketAddress(uint16_t port)
        {
            GetAsSockAddrIn()->sin_family = AF_INET;
            GetIPv4Ref() = INADDR_ANY;
            GetAsSockAddrIn()->sin_port = htons(port);
        }

        SocketAddress::SocketAddress()
        {
            GetAsSockAddrIn()->sin_family = AF_INET;
            GetIPv4Ref() = INADDR_ANY;
            GetAsSockAddrIn()->sin_port = 0;
        }

        SocketAddress::SocketAddress(const sockaddr& sockAddr)
        {
#ifdef HT_SYS_WINDOWS
            memcpy_s(&m_sockAddr, sizeof(sockaddr), &sockAddr, sizeof(sockaddr));
#else
            std::memcpy(&m_sockAddr, &sockAddr, sizeof(sockaddr));
#endif
        }

        bool SocketAddress::operator== (const SocketAddress& other) const
        {
            //If family types do not match, return immediately false
            if(m_sockAddr.sa_family != other.GetAsSockAddrIn()->sin_family)
                return false;

            //IPv4 comparison
            if(m_sockAddr.sa_family == AF_INET)
            {
                return ((GetAsSockAddrIn()->sin_port == other.GetAsSockAddrIn()->sin_port) &&
                        (GetIPv4Ref() == other.GetIPv4Ref()));       
            }
            else if(m_sockAddr.sa_family == AF_INET6)
            {
                return false;
            }


            return false;
        }

        size_t SocketAddress::GetSize() const
        {
            return sizeof(sockaddr);
        }
        
        uint32_t& SocketAddress::GetIPv4Ref()
        {
#ifdef HT_SYS_WINDOWS
            return *reinterpret_cast<uint32_t*>(&GetAsSockAddrIn()->sin_addr.S_un.S_addr);
#else
            return GetAsSockAddrIn()->sin_addr.s_addr;
#endif
        }
        
        const uint32_t& SocketAddress::GetIPv4Ref() const
        {
#ifdef HT_SYS_WINDOWS
            return *reinterpret_cast<const uint32_t*>(&GetAsSockAddrIn()->sin_addr.S_un.S_addr);
#else
            return GetAsSockAddrIn()->sin_addr.s_addr;
#endif
        }

        sockaddr_in* SocketAddress::GetAsSockAddrIn()
        {
            return reinterpret_cast<sockaddr_in*>(&m_sockAddr);
        }
        
        const sockaddr_in* SocketAddress::GetAsSockAddrIn() const
        {
            return reinterpret_cast<const sockaddr_in*>(&m_sockAddr);
        }
    }
}
