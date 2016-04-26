/**
**    Hatchit Engine
**    Copyright(c) 2015 Third-Degree
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

#include <ht_network.h>
#include <ht_debug.h>
#include <cstring>

namespace Hatchit {

    namespace Network {

        void ReportError(const char* err)
        {
#ifdef HT_SYS_WINDOWS
            LPVOID msgBuffer;
            DWORD errorNum = WSAGetLastError();

            FormatMessageA(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                errorNum,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (LPSTR)&msgBuffer,
                0, NULL);
            HT_ERROR_PRINTF("%s. %s\n", err, msgBuffer);
#else
            HT_ERROR_PRINTF("%s. %s\n", err, strerror(errno));
#endif
        }

        int LastError()
        {
#ifdef HT_SYS_WINDOWS
            return 0;
#else
            return errno;
#endif
        }

        bool Initialize()
        {
#ifdef HT_SYS_WINDOWS
            WSADATA wsaData;
            int result = WSAStartup(WINSOCK_VERSION, &wsaData);
            if (result != NO_ERROR)
            {
#ifdef _DEBUG
                ReportError("Network::Initialize Failed.");
#endif
                return false;
            }
#endif
            return true;
        }

        void Shutdown()
        {
#ifdef HT_SYS_WINDOWS
            int result = WSACleanup();
            if (result != NO_ERROR)
            {
#ifdef _DEBUG
                ReportError("Network::Shutdown Failed.");
#endif
            }
#endif
        }
    }
}
