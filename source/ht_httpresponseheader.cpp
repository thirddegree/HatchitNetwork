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

#include <ht_httpresponseheader.h>

namespace Hatchit
{
    namespace Network
    {
        
        HTTPResponseHeader::HTTPResponseHeader() 
        {
        
        }

        std::string HTTPResponseHeader::GetAccessControlAllowOrigin()
        {
            return m_parameters["Access-Control-Allow-Origin"];
        }
        std::string HTTPResponseHeader::GetAcceptPatch() 
        {
            return m_parameters["Accept-Patch"];
        }
        std::string HTTPResponseHeader::GetAcceptRanges() 
        {
            return m_parameters["Accept-Ranges"];
        }
        std::string HTTPResponseHeader::GetAge() 
        {
            return m_parameters["Age"];
        }
        std::string HTTPResponseHeader::GetAllow() 
        {
            return m_parameters["Allow"];
        }
        std::string HTTPResponseHeader::GetAltSvc() 
        {
            return m_parameters["Alt-Svc"];
        }
        std::string HTTPResponseHeader::GetCacheControl() 
        {
            return m_parameters["Cache-Control"];
        }
        std::string HTTPResponseHeader::GetConnection() 
        {
            return m_parameters["Connection"];
        }
        std::string HTTPResponseHeader::GetContentDisposition() 
        {
            return m_parameters["Content-Disposition"];
        }
        std::string HTTPResponseHeader::GetContentEncoding() 
        {
            return m_parameters["Content-Encoding"];
        }
        std::string HTTPResponseHeader::GetContentLanguage() 
        {
            return m_parameters["Content-Language"];
        }
        std::string HTTPResponseHeader::GetContentLength() 
        {
            return m_parameters["Content-Length"];
        }
        std::string HTTPResponseHeader::GetContentLocation() 
        {
            return m_parameters["Content-Location"];
        }
        std::string HTTPResponseHeader::GetContentRange() 
        {
            return m_parameters["Content-Range"];
        }
        std::string HTTPResponseHeader::GetContentType() 
        {
            return m_parameters["Content-Type"];
        }
        std::string HTTPResponseHeader::GetDate() 
        {
            return m_parameters["Date"];
        }
        std::string HTTPResponseHeader::GetETag() 
        {
            return m_parameters["ETag"];
        }
        std::string HTTPResponseHeader::GetExpires() 
        {
            return m_parameters["Expires"];
        }
        std::string HTTPResponseHeader::GetLastModified() 
        {
            return m_parameters["Last-Modified"];
        }
        std::string HTTPResponseHeader::GetLink() 
        {
            return m_parameters["Link"];
        }
        std::string HTTPResponseHeader::GetLocation() 
        {
            return m_parameters["Location"];
        }
        std::string HTTPResponseHeader::GetP3P() 
        {
            return m_parameters["P3P"];
        }
        std::string HTTPResponseHeader::GetPragma() 
        {
            return m_parameters["Pragma"];
        }
        std::string HTTPResponseHeader::GetProxyAuthenticate() 
        {
            return m_parameters["Proxy-Authenticate"];
        }
        std::string HTTPResponseHeader::GetPublicKeyPins() 
        {
            return m_parameters["Public-Key-Pins"];
        }
        std::string HTTPResponseHeader::GetRefresh() 
        {
            return m_parameters["Refresh"];
        }
        std::string HTTPResponseHeader::GetRetryAfter() 
        {
            return m_parameters["Retry-After"];
        }
        std::string HTTPResponseHeader::GetServer() 
        {
            return m_parameters["Server"];
        }
        std::string HTTPResponseHeader::GetSetCookie() 
        {
            return m_parameters["Set-Cookie"];
        }
        std::string HTTPResponseHeader::GetStatus() 
        {
            return m_parameters["Status"];
        }
        std::string HTTPResponseHeader::GetStrictTransportSecurity() 
        {
            return m_parameters["Strict-Transport-Security"];
        }
        std::string HTTPResponseHeader::GetTrailer() 
        {
            return m_parameters["Trailer"];
        }
        std::string HTTPResponseHeader::GetTransferEncoding() 
        {
            return m_parameters["Transfer-Encoding"];
        }
        std::string HTTPResponseHeader::GetTSV() 
        {
            return m_parameters["TSV"];
        }
        std::string HTTPResponseHeader::GetUpgrade() 
        {
            return m_parameters["Upgrade"];
        }
        std::string HTTPResponseHeader::GetVary() 
        {
            return m_parameters["Vary"];
        }
        std::string HTTPResponseHeader::GetVia() 
        {
            return m_parameters["Via"];
        }
        std::string HTTPResponseHeader::GetWarning() 
        {
            return m_parameters["Warning"];
        }
        std::string HTTPResponseHeader::GetWWWAuthenticate() 
        {
            return m_parameters["WWW-Authenticate"];
        }


        void HTTPResponseHeader::Set(std::string key, std::string parameter) 
        {
            m_parameters[key] = parameter;
        }
    }
}