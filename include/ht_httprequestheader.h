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

#include <ht_httpheader.h>

namespace Hatchit
{
    namespace Network
    {
        class HT_API HTTPRequestHeader : public HTTPHeader
        {
        public:
            HTTPRequestHeader();

            void SetAccept(std::string accept);
            void SetAcceptCharset(std::string acceptCharset);
            void SetAcceptEncoding(std::string acceptEncoding);
            void SetAcceptLanguage(std::string acceptLanguage);
            void SetAcceptDateTime(std::string acceptDateTime);
            void SetAuthorization(std::string authorization);
            void SetCacheControl(std::string cacheControl);
            void SetConnection(std::string connection);
            void SetCookie(std::string cookie);
            void SetContentLength(std::string contentLength);
            void SetContentType(std::string contentType);
            void SetDate(std::string date);
            void SetExpect(std::string expect);
            void SetForwarded(std::string forwarded);
            void SetFrom(std::string from);
            void SetHost(std::string host);
            void SetIfMatch(std::string ifMatch);
            void SetIfModifiedSince(std::string ifModifiedSince);
            void SetIfNoneMatch(std::string ifNoneMatch);
            void SetIfRange(std::string ifRange);
            void SetIfUnmodifiedSince(std::string ifUnmodifiedSince);
            void SetMaxForwards(std::string maxForwards);
            void SetOrigin(std::string origin);
            void SetPragma(std::string pragma);
            void SetProxyAuthorization(std::string proxyAuthorization);
            void SetRange(std::string range);
            void SetReferer(std::string referer);
            void SetTE(std::string te);
            void SetUserAgent(std::string userAgent);
            void SetUpgrade(std::string upgrade);
            void SetVia(std::string via);
            void SetWarning(std::string warning);
        };
    }
}