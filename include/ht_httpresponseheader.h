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
        class HT_API HTTPResponseHeader : public HTTPHeader
        {
        public:
            HTTPResponseHeader();

            std::string GetAccessControlAllowOrigin();
            std::string GetAcceptPatch();
            std::string GetAcceptRanges();
            std::string GetAge();
            std::string GetAllow();
            std::string GetAltSvc();
            std::string GetCacheControl();
            std::string GetConnection();
            std::string GetContentDisposition();
            std::string GetContentEncoding();
            std::string GetContentLanguage();
            std::string GetContentLength();
            std::string GetContentLocation();
            std::string GetContentRange();
            std::string GetContentType();
            std::string GetDate();
            std::string GetETag();
            std::string GetExpires();
            std::string GetLastModified();
            std::string GetLink();
            std::string GetLocation();
            std::string GetP3P();
            std::string GetPragma();
            std::string GetProxyAuthenticate();
            std::string GetPublicKeyPins();
            std::string GetRefresh();
            std::string GetRetryAfter();
            std::string GetServer();
            std::string GetSetCookie();
            std::string GetStatus();
            std::string GetStrictTransportSecurity();
            std::string GetTrailer();
            std::string GetTransferEncoding();
            std::string GetTSV();
            std::string GetUpgrade();
            std::string GetVary();
            std::string GetVia();
            std::string GetWarning();
            std::string GetWWWAuthenticate();
            
        private:
            void Set(std::string key, std::string parameter);

            friend class HTTPResponse;
        };
    }
}