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

#pragma once

#include <ht_platform.h>

#ifdef HT_SYS_WINDOWS
#include <Winsock2.h>   //WIN32 Socket API
#else
#include <sys/socket.h> //POSIX Socket API
#include <netinet/in.h> //IPv4 functionality
#include <arpa/inet.h>  //Address conversion
#include <netdb.h>      //Name resolution
#endif

namespace Hatchit {

    namespace Network {
        
        HT_API
        void ReportError(const char* err);
    }
}

