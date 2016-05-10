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

#include <ht_http.h>

namespace Hatchit
{
    namespace Network
    {
        SocketAddressPtr HTTP::m_address;
        TCPSocketPtr     HTTP::m_socket;

        bool HTTP::GET(std::string address, std::string& returnBody)
        {
            HTTPRequest request(HTTPRequest::Type::GET, address);
            request.SetHeader("Accept: */*\nAccept-Encoding: gzip, deflate");

            return SubmitRequest(request, returnBody);
        }
        bool HTTP::POST(std::string address, std::string body, std::string& returnBody)
        {
        
        }

        bool HTTP::SubmitRequest(HTTPRequest request, std::string& returnBody)
        {
            m_address = SocketUtil::CreateIPv4Address(request.GetAddress());
            m_socket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

            m_socket->Bind(*m_address);
        }
        
    }
}