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
#ifndef _XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_HPP
#define _XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_HPP

#include "xos/protocol/http/message/header/field/Which.hpp"
#include "xos/base/CharsWrapped.hpp"

#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_ENCODING "Content-Encoding"
#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_LENGTH "Content-Length"
#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_TYPE "Content-Type"
#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_DISPOSITION "Content-Disposition"

#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAMES \
    XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_ENCODING , \
    XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_LENGTH , \
    XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_TYPE , \
    XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_CONTENT_DISPOSITION , \

namespace xos {
namespace protocol {
namespace http {
namespace message {
namespace header {
namespace field {

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
    NameT(field::Which which): Extends(OfWhich(which)), m_which(which) {
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
    virtual NameT& operator = (field::Which which) {
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
    virtual field::Which Which() const {
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
            XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAMES
            0
        };
        return name;
    }
    static const char_t* OfWhich(field::Which which) {
        const char_t** name = OfWhich();
        if ((name) && (which >= First) && (which <= Last)) {
            return name[which - First];
        }
        return 0;
    }
    static field::Which WhichOf(const char_t* of) {
        if ((of)) {
            const char_t* to = 0;
            for (field::Which which = First; which <= Last; ++which) {
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
    field::Which m_which;
};
typedef NameT<> Name;

} // namespace field
} // namespace header 
} // namespace message 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_MESSAGE_HEADER_FIELD_NAME_HPP 

        

