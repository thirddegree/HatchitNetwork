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
#include <ht_httpresponseheader.h>  //HTTPResponseHeader
#include <ht_string.h>              //std::string

namespace Hatchit 
{
    namespace Network 
    {
        class HT_API HTTPResponse 
        {
        public:
            HTTPResponse();

            bool ParseResponse(std::string rawResponse);

            HTTPResponseHeader GetHeader() const;
            std::string GetBody() const;

        private:
            HTTPResponseHeader m_header;
            std::string m_body;

            void parseHeader(std::string rawHeader);
        };
    }
}
