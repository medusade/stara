///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Method.hpp
///
/// Author: $author$
///   Date: 3/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_HTTP_REQUEST_METHOD_HPP
#define _STARA_PROTOCOL_HTTP_REQUEST_METHOD_HPP

#include "stara/protocol/xttp/request/Method.hpp"

#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_GET "GET"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_POST "POST"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_TRACE "TRACE"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_CONNECT "CONNECT"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_HEAD "HEAD"
#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PATCH "PATCH"

#define STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAMES \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_GET, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_POST, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PUT, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_DELETE, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_TRACE, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_CONNECT, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_OPTIONS, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_HEAD, \
    STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PATCH

namespace stara {
namespace protocol {
namespace http {
namespace request {

typedef xttp::request::MethodTImplements MethodTImplements;
typedef xttp::request::Method MethodTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MethodT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MethodTImplements, class TExtends = MethodTExtends>

class _EXPORT_CLASS MethodT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef int WhichOf;
    enum {
        None = 0,
        GET, POST, PUT, DELETE, TRACE, CONNECT, OPTIONS, HEAD, PATCH,
        Extension, First = (None + 1), Last = (Extension - 1),
        Count = ((Last - First) + 1)
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MethodT(const String& s)
    : Extends(s),
      m_which(OfName(this->chars())) {
    }
    MethodT(const char* chars, size_t length)
    : Extends(chars, length),
      m_which(OfName(this->chars())) {
    }
    MethodT(const char* chars)
    : Extends(chars),
      m_which(OfName(this->chars())) {
    }
    MethodT(const WhichOf& which)
    : Extends(NameOfChars(which)),
      m_which(which) {
    }
    MethodT(const Extends& method)
    : Extends(method),
      m_which(OfName(this->chars())) {
    }
    MethodT(const MethodT& copy)
    : Extends(copy),
      m_which(copy.m_which) {
    }
    MethodT()
    : Extends(STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAME_GET),
      m_which(GET) {
    }
    virtual ~MethodT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WhichOf Which() const {
        return m_which;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static WhichOf OfName(const String& name) {
        return OfName(name.chars());
    }
    static String NameOf(WhichOf which) {
        String nameOf(NameOfChars);
        return nameOf;
    }
    static WhichOf OfName(const char* name) {
        if ((name)) {
            const char* toName = 0;
            for (WhichOf which = First; which <= Last; ++which) {
                if ((toName = NameOfChars(which))) {
                    if (!(Chars::compare(name, toName))) {
                        return which;
                    }
                }
            }
            return Extension;
        }
        return None;
    }
    static const char* NameOfChars(WhichOf which) {
        static const char* of[Count] = {
            STARA_PROTOCOL_HTTP_REQUEST_METHOD_NAMES
        };
        if ((which >= First) && (which <= Last)) {
            return of[which - First];
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    WhichOf m_which;
};
typedef MethodT<> Method;

} // namespace request 
} // namespace http 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_HTTP_REQUEST_METHOD_HPP 
