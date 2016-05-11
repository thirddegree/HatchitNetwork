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

#include <ht_httpresponse.h>

namespace Hatchit
{
    namespace Network
    {
        HTTPResponse::HTTPResponse() 
        {
            m_body = "";
        }

        bool HTTPResponse::ParseResponse(std::string rawResponse) 
        {
            //Split the response into two parts, header and body
            //That split point is where we find the string "\r\n\r\n"; two newlines
            std::string newlines = "\r\n\r\n";
            size_t endOfHeader = rawResponse.find(newlines, 0) + 2;

            std::string rawHeader = rawResponse.substr(0, endOfHeader);
            parseHeader(rawHeader);

            //The rest of the string is the body
            m_body = rawResponse.substr(endOfHeader + 2);

            return true;
        }

        HTTPResponseHeader HTTPResponse::GetHeader() const 
        {
            return m_header;
        }
        std::string HTTPResponse::GetBody() const 
        {
            return m_body;
        }

        void HTTPResponse::parseHeader(std::string rawHeader)
        {
            size_t parsed = 0;

            //Take the raw header line by line and break up the parameters
            while (parsed < rawHeader.size())
            {
                size_t endOfLine = rawHeader.find("\r\n", parsed);
                size_t length = endOfLine - parsed;

                //Skip first line
                if (parsed != 0)
                {
                    std::string line = rawHeader.substr(parsed, length);

                    size_t endOfKey = line.find_first_of(":", 0);

                    std::string key = line.substr(0, endOfKey);
                    std::string param = line.substr(endOfKey + 2); //+2 because the layout will be "key: param"

                    //Manually set the pairs into the header
                    m_header.Set(key, param);
                }

                parsed += length + 2;
            }
        }
    }
}
