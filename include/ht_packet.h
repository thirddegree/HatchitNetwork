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

#include <ht_platform.h>
#include <ht_network.h>

namespace Hatchit
{
    namespace Network
    {
        class SocketAddress;

        class Packet
        {
        public:

        private:
            SocketAddress m_address;
            BYTE*         m_data;
            uint32_t      m_length;

            bool m_local;
        };
    }
}