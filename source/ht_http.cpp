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
#include <iterator>
#include <iostream>

namespace Hatchit
{
    namespace Network
    {
        SocketAddressPtr HTTP::m_address;
        TCPSocketPtr     HTTP::m_socket;

        bool HTTP::GET(std::string address, HTTPResponse& response)
        {
            HTTPRequest request(HTTPRequest::Type::GET, address);

            HTTPRequestHeader header;

            request.SetHeader(header);

            return SubmitRequest(request, response);
        }
        bool HTTP::POST(std::string address, std::string body, std::string& returnBody)
        {
            return true;
        }

        bool HTTP::SubmitRequest(HTTPRequest request, HTTPResponse& response)
        {
            //Resolve hostname
            std::string hostname = request.GetHostname();
            uint32_t port = request.GetPort();

            hostent* h = gethostbyname(hostname.c_str());
            char* addr = inet_ntoa(*((struct in_addr *) h->h_addr_list[0]));

            std::string ip = std::string(addr);
            ip.append(":");
            ip.append(std::to_string(port));

            m_address = SocketUtil::CreateIPv4Address(ip);

            if (m_address == nullptr)
                return false;

            m_socket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

            if (m_socket->Connect(*m_address) < 0)
                return false;

            std::string packet = "";
            packet.append(request.GetHeader());
            packet.append("\r\n");
            
            if (m_socket->Send(packet.c_str(), static_cast<int>(packet.size())) < 0)
                return false;

            //Recieve data in 50 byte chunks until we've parsed as far as we need to in order to learn the buffer size
            std::string rawResponse;
            size_t responseSize = 0;
            size_t bodySize = 0;

            size_t chunkSize = 100;

            while (bodySize == 0)
            {
                //Add 1 for the null terminator
                char* chunk = new char[chunkSize + 1];
                size_t recievedByteCount = 0;
                if ((recievedByteCount = m_socket->Receive(chunk, static_cast<int>(chunkSize))) < 0)
                    return false;

                rawResponse.append(chunk);
                responseSize += recievedByteCount;
                delete[] chunk;

                if (recievedByteCount < chunkSize)
                {
                    bodySize = responseSize;
                    break;
                }
            }

            response.ParseResponse(rawResponse);
            
            return true;
        }
        
    }
}