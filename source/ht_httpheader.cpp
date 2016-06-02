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

#include <ht_httpheader.h>    //HTTPHeader

namespace Hatchit
{
    namespace Network
    {
        std::string HTTPHeader::GetHeaderString()
        {
            std::string header;

            for (auto it = m_parameters.begin(); it != m_parameters.end(); it++)
            {
                header.append(it->first);
                header.append(":");

                header.append(it->second);
                header.append("\r\n");
            }

            //Append an extra newline to mark the end of the file
            header.append("\r\n");

            return header;
        }
    }
}
