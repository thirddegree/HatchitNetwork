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
#include <memory>

namespace Hatchit {

    namespace Network {

        class HT_API SocketAddress
        {
        public:
            SocketAddress(uint32_t address, uint16_t port, int family = AF_INET);
            SocketAddress(const sockaddr& sockAddr);

            size_t GetSize() const;

            bool operator== (const SocketAddress& other) const;
        private:
            sockaddr m_sockAddr;

            uint32_t&           GetIPv4Ref();
            const uint32_t&     GetIPv4Ref() const;
            sockaddr_in*        GetAsSockAddrIn();
            const sockaddr_in*  GetAsSockAddrIn() const;
        };
        typedef std::shared_ptr<SocketAddress> SocketAddressPtr;
    }
}
