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

#include <ht_platform.h>            //HT_API
#include <ht_string.h>              //std::string
#include <ht_httprequestheader.h>   //HTTPRequestHeader

namespace Hatchit
{
    namespace Network
    {
        class HT_API HTTPRequest
        {
        public:
            enum class Type
            {
                GET,
                POST
            };

            HTTPRequest(Type type, std::string url);
            HTTPRequest(Type type, std::string url, uint32_t port);
            ~HTTPRequest();

            void SetHeader(HTTPRequestHeader header);
            void SetBody(std::string body);

            std::string GetHostname() const;
            std::string GetHeader();
            uint32_t    GetPort() const;
            std::string GetBody() const;

        private:
            Type        m_type;
            std::string m_url;
            std::string m_hostname;
            std::string m_uri;
            uint32_t    m_port;

            HTTPRequestHeader  m_header;
            std::string m_body;

            std::string getHostnameFromURL(std::string url);
            std::string getURIFromURL(std::string url);
        };
    }
}