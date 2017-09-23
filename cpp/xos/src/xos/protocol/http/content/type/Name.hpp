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
///   File: Name.hpp
///
/// Author: $author$
///   Date: 9/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_HPP
#define _XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_HPP

#include "xos/protocol/http/content/type/Which.hpp"
#include "xos/base/CharsWrapped.hpp"

#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_TEXT "text/plain"
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_HTML "text/html"
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_XML "text/xml"
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_OCTET_STREAM "application/octet-stream"
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_URLENCODED_FORM_DATA "application/x-www-form-urlencoded"
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_MULTIPART_FORM_DATA "multipart/form-data"
#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_UNKNOWN "unknown"

#define XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAMES \
    XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_TEXT, \
    XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_HTML, \
    XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_XML, \
    XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_OCTET_STREAM, \
    XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_URLENCODED_FORM_DATA, \
    XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_MULTIPART_FORM_DATA, \

namespace xos {
namespace protocol {
namespace http {
namespace content {
namespace type {

typedef ImplementBase NameTImplements;
typedef CharsWrapped NameTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: NameT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = NameTImplements, class TExtends = NameTExtends>
class _EXPORT_CLASS NameT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::chars_t chars_t;
    typedef typename Extends::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    NameT(type::Which which): Extends(OfWhich(which)), m_which(which) {
    }
    NameT(const NameT& copy): Extends(copy), m_which(copy.m_wich) {
    }
    virtual ~NameT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual NameT& operator = (const char_t* of) {
        m_which = WhichOf(this->SetWrapped(of));
        return *this;
    }
    virtual NameT& operator = (type::Which which) {
        this->SetWrapped(OfWhich(m_which = which));
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Of(size_t& length) const {
        length = Length();
        return Of();
    }
    virtual const char_t* Of() const {
        return this->Wrapped();
    }
    virtual type::Which Which() const {
        return m_which;
    }
    virtual size_t Length() const {
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->wrapped())) {
            length = chars_t::count(chars);
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static const char_t** OfWhich() {
        static const char_t* name[Count + 1] = {
            XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAMES
            0
        };
        return name;
    }
    static const char_t* OfWhich(type::Which which) {
        const char_t** name = OfWhich();
        if ((name) && (which >= First) && (which <= Last)) {
            return name[which - First];
        }
        return 0;
    }
    static type::Which WhichOf(const char_t* of) {
        if ((of)) {
            const char_t* to = 0;
            for (type::Which which = First; which <= Last; ++which) {
                if ((to = OfWhich(which))) {
                    if (!(chars_t::compare(of, to)))
                        return which;
                }
            }
        }
        return None;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    type::Which m_which;
};
typedef NameT<> Name;

} // namespace type
} // namespace content 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_CONTENT_TYPE_NAME_HPP 

        

