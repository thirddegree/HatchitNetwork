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

            HTTPRequest(Type type, std::string address);
            ~HTTPRequest();

            void SetHeader(std::string header);
            void SetBody(std::string body);

            std::string GetAddress() const;
            std::string GetHeader() const;
            std::string GetBody() const;

        private:
            Type m_type;
            std::string m_address;
            std::string m_header;
            std::string m_body;
        };
    }
}