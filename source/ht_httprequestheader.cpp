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

#include <ht_httprequestheader.h>    //HTTPRequestHeader

namespace Hatchit
{
    namespace Network
    {
        HTTPRequestHeader::HTTPRequestHeader()
        {
            //Set some absolute basics
            SetAccept("text/plain");
            SetAcceptCharset("utf-8");
            SetAcceptEncoding("gzip, deflate");
            SetAcceptLanguage("en-US");
        }

        void HTTPRequestHeader::SetAccept(std::string accept)
        {
            m_parameters["Accept"] = accept;
        }
        void HTTPRequestHeader::SetAcceptCharset(std::string acceptCharset)
        {
            m_parameters["Accept-Charset"] = acceptCharset;
        }
        void HTTPRequestHeader::SetAcceptEncoding(std::string acceptEncoding)
        {
            m_parameters["Accept-Encoding"] = acceptEncoding;
        }
        void HTTPRequestHeader::SetAcceptLanguage(std::string acceptLanguage)
        {
            m_parameters["Accept-Language"] = acceptLanguage;
        }
        void HTTPRequestHeader::SetAcceptDateTime(std::string acceptDateTime)
        {
            m_parameters["Accept-Datetime"] = acceptDateTime;
        }
        void HTTPRequestHeader::SetAuthorization(std::string authorization)
        {
            m_parameters["Authorization"] = authorization;
        }
        void HTTPRequestHeader::SetCacheControl(std::string cacheControl)
        {
            m_parameters["cacheControl"] = cacheControl;
        }
        void HTTPRequestHeader::SetConnection(std::string connection)
        {
            m_parameters["Connection"] = connection;
        }
        void HTTPRequestHeader::SetCookie(std::string cookie)
        {
            m_parameters["Cookie"] = cookie;
        }
        void HTTPRequestHeader::SetContentLength(std::string contentLength)
        {
            m_parameters["Content-Length"] = contentLength;
        }
        void HTTPRequestHeader::SetContentType(std::string contentType)
        {
            m_parameters["Content-Type"] = contentType;
        }
        void HTTPRequestHeader::SetDate(std::string date)
        {
            m_parameters["Date"] = date;
        }
        void HTTPRequestHeader::SetExpect(std::string expect)
        {
            m_parameters["Expect"] = expect;
        }
        void HTTPRequestHeader::SetForwarded(std::string forwarded)
        {
            m_parameters["Forwarded"] = forwarded;
        }
        void HTTPRequestHeader::SetFrom(std::string from)
        {
            m_parameters["From"] = from;
        }
        void HTTPRequestHeader::SetHost(std::string host)
        {
            m_parameters["Host"] = host;
        }
        void HTTPRequestHeader::SetIfMatch(std::string ifMatch)
        {
            m_parameters["If-Match"] = ifMatch;
        }
        void HTTPRequestHeader::SetIfModifiedSince(std::string ifModifiedSince)
        {
            m_parameters["If-Modified-Since"] = ifModifiedSince;
        }
        void HTTPRequestHeader::SetIfNoneMatch(std::string ifNoneMatch)
        {
            m_parameters["If-None-Match"] = ifNoneMatch;
        }
        void HTTPRequestHeader::SetIfRange(std::string ifRange)
        {
            m_parameters["If-Range"] = ifRange;
        }
        void HTTPRequestHeader::SetIfUnmodifiedSince(std::string ifUnmodifiedSince)
        {
            m_parameters["If-Unmodified-Since"] = ifUnmodifiedSince;
        }
        void HTTPRequestHeader::SetMaxForwards(std::string maxForwards)
        {
            m_parameters["Max-Forwards"] = maxForwards;
        }
        void HTTPRequestHeader::SetOrigin(std::string origin)
        {
            m_parameters["Origin"] = origin;
        }
        void HTTPRequestHeader::SetPragma(std::string pragma)
        {
            m_parameters["Pragma"] = pragma;
        }
        void HTTPRequestHeader::SetProxyAuthorization(std::string proxyAuthorization)
        {
            m_parameters["Proxy-Authorization"] = proxyAuthorization;
        }
        void HTTPRequestHeader::SetRange(std::string range)
        {
            m_parameters["Range"] = range;
        }
        void HTTPRequestHeader::SetReferer(std::string referer)
        {
            m_parameters["Referer"] = referer;
        }
        void HTTPRequestHeader::SetTE(std::string te)
        {
            m_parameters["TE"] = te;
        }
        void HTTPRequestHeader::SetUserAgent(std::string userAgent)
        {
            m_parameters["User-Agent"] = userAgent;
        }
        void HTTPRequestHeader::SetUpgrade(std::string upgrade)
        {
            m_parameters["Upgrade"] = upgrade;
        }
        void HTTPRequestHeader::SetVia(std::string via)
        {
            m_parameters["Via"] = via;
        }
        void HTTPRequestHeader::SetWarning(std::string warning)
        {
            m_parameters["Warning"] = warning;
        }

    }
}
