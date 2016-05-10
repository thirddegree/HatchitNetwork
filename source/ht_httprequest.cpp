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
        HTTPRequest::HTTPRequest(HTTPRequest::Type type, std::string address) 
        {
            m_type = type;
            m_address = address;
            m_header = "";
            m_body = "";
        }
        HTTPRequest::~HTTPRequest() {}

        void HTTPRequest::SetHeader(std::string header)
        {
            m_header = header;
        }
        void HTTPRequest::SetBody(std::string body)
        {
            m_body = body;
        }

        std::string HTTPRequest::GetAddress() const
        {
            return m_address;
        }
        std::string HTTPRequest::GetHeader() const
        {
            return m_header;
        }
        std::string HTTPRequest::GetBody() const
        {
            return m_body;
        }
    }
}