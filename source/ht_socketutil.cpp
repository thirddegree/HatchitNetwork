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

#include <ht_socketutil.h>
#include <ht_debug.h>
#include <cstring>

namespace Hatchit {

    namespace Network {
    
        SocketAddressPtr SocketUtil::CreateIPv4Address(const std::string& address)
        {
            auto pos = address.find_last_of(':');
            std::string host;
            std::string service;
            if(pos != std::string::npos) //if address has specified service port
            {
                host = address.substr(0, pos);
                service = address.substr(pos + 1);
            }
            else
            {
                host = address;
                service = "0";
            }

            addrinfo hint;
            std::memset(&hint, 0, sizeof(addrinfo));
            hint.ai_family = AF_INET; //IPv4 family

            addrinfo* result;
            int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
            if(error != 0 && result != nullptr)
            {
#ifdef _DEBUG
                Core::DebugPrintF("ERROR: IPv4FromString failed: %s\n", strerror(errno));
#endif              
                freeaddrinfo(result);
                return nullptr;
            }

            while(!result->ai_addr && result->ai_next)
                result = result->ai_next;


            if(!result->ai_addr)
            {
                freeaddrinfo(result);
                return nullptr;
            }

            auto retVal = std::make_shared<SocketAddress>(*result->ai_addr);

            freeaddrinfo(result);

            return retVal;
        }
    }
}
