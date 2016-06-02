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

#pragma once

#include <ht_platform.h>
#include <ht_string.h>
#include <ht_httprequest.h>
#include <ht_httpresponse.h>
#include <ht_socketutil.h>

namespace Hatchit
{
    namespace Network
    {
        class HT_API HTTP 
        {
        public:
            static bool GET(std::string address, HTTPResponse& response);
            static bool GET(std::string address, HTTPRequestHeader header, HTTPResponse& response);

            static bool POST(std::string address, std::string body, std::string& returnBody);

        private:
            static bool SubmitRequest(HTTPRequest request, HTTPResponse& response);

            static SocketAddressPtr m_address;
            static TCPSocketPtr     m_socket;
        };
    }
}