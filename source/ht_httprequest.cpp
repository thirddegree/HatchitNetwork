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

#include <ht_httprequest.h>

namespace Hatchit
{
    namespace Network
    {
        HTTPRequest::HTTPRequest(HTTPRequest::Type type, std::string url) 
        {
            m_type = type;
            m_url = url;

            m_hostname = getHostnameFromURL(url);
            m_uri = getURIFromURL(url);
            
            m_port = 80;
            m_body = "";
        }
        HTTPRequest::HTTPRequest(HTTPRequest::Type type, std::string url, uint32_t port)
        {
            m_type = type;
            m_url = url;

            m_hostname = getHostnameFromURL(url);
            m_uri = getURIFromURL(url);

            m_port = port;
            m_body = "";
        }

        HTTPRequest::~HTTPRequest() {}

        void HTTPRequest::SetHeader(HTTPRequestHeader header)
        {
            m_header = header;
        }
        void HTTPRequest::SetBody(std::string body)
        {
            m_body = body;
        }

        std::string HTTPRequest::GetHostname() const
        {
            return m_hostname;
        }
        std::string HTTPRequest::GetHeader()
        {
            std::string headerString = "";

            //Append the type of the request to the header
            switch (m_type)
            {
            case HTTPRequest::Type::GET:
                headerString.append("GET ");
                break;
            case HTTPRequest::Type::POST:
                headerString.append("POST ");
                break;
            }

            //Append the uri of the request
            headerString.append(m_uri);
            headerString.append(" HTTP/1.1");
            headerString.append("\r\n");

            //Set the host of the header
            std::string host = m_hostname;
            //host.append(":");
            //host.append(std::to_string(m_port));
            m_header.SetHost(host);

            //Append the rest of the header
            headerString.append(m_header.GetHeaderString());

            return headerString;
        }

        uint32_t HTTPRequest::GetPort() const 
        {
            return m_port;
        }

        std::string HTTPRequest::GetBody() const
        {
            return m_body;
        }

        std::string HTTPRequest::getHostnameFromURL(std::string url) 
        {
            size_t endOfProtocol;
            size_t endOfHostname;

            endOfProtocol = url.find_first_of("://", 0);
            endOfProtocol += 3;

            endOfHostname = url.find_first_of("/", endOfProtocol);
            if (endOfHostname < endOfProtocol)
                endOfHostname = url.size() - 1;

            size_t hostnameLength = endOfHostname - endOfProtocol;

            return url.substr(endOfProtocol, hostnameLength);
        }
        std::string HTTPRequest::getURIFromURL(std::string url) 
        {
            size_t endOfProtocol;
            size_t endOfHostname;

            endOfProtocol = url.find_first_of("://", 0);
            endOfProtocol += 3;

            endOfHostname = url.find_first_of("/", endOfProtocol);
            if (endOfHostname < endOfProtocol)
                endOfHostname = url.size() - 1;

            std::string uri = url.substr(endOfHostname);
            return uri;
        }

    }
}