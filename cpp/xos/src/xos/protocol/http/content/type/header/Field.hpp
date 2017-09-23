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
///   File: Field.hpp
///
/// Author: $author$
///   Date: 9/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_CONTENT_TYPE_HEADER_FIELD_HPP
#define _XOS_PROTOCOL_HTTP_CONTENT_TYPE_HEADER_FIELD_HPP

#include "xos/protocol/http/content/type/Name.hpp"
#include "xos/protocol/http/content/type/Which.hpp"
#include "xos/protocol/http/header/Field.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace content {
namespace type {
namespace header {

typedef http::header::FieldTImplements FieldTImplements;
typedef http::header::Field FieldTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FieldT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = FieldTImplements,
 class TExtends = FieldTExtends>

class _EXPORT_CLASS FieldT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldT(http::content::type::Which which)
    : Extends
      (http::message::header::field::ContentType,
       http::content::type::Name::OfWhich(which)) {
    }
    FieldT(const FieldT& copy): Extends(copy) {
    }
    FieldT(): Extends(http::message::header::field::ContentType) {
    }
    virtual ~FieldT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FieldT<> Field;

} // namespace header

namespace text {
namespace header {
typedef type::header::Field FieldExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Field: public FieldExtends {
public: Field(): FieldExtends(http::content::type::Text) {}
};
} // namespace header
} // namespace text

namespace html {
namespace header {
typedef type::header::Field FieldExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Field: public FieldExtends {
public: Field(): FieldExtends(http::content::type::Html) {}
};
} // namespace header
} // namespace html

namespace xml {
namespace header {
typedef type::header::Field FieldExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Field: public FieldExtends {
public: Field(): FieldExtends(http::content::type::Xml) {}
};
} // namespace header
} // namespace xml

namespace octetstream {
namespace header {
typedef type::header::Field FieldExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Field: public FieldExtends {
public: Field(): FieldExtends(http::content::type::OctetStream) {}
};
} // namespace header
} // namespace octetstream

namespace urlencodedformdata {
namespace header {
typedef type::header::Field FieldExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Field: public FieldExtends {
public: Field(): FieldExtends(http::content::type::UrlEncodedFormData) {}
};
} // namespace header
} // namespace urlencodedformdata

namespace multipartformdata {
namespace header {
typedef type::header::Field FieldExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Field: public FieldExtends {
public: Field(): FieldExtends(http::content::type::MultipartFormData) {}
};
} // namespace header
} // namespace multipartformdata

} // namespace type
} // namespace content 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_CONTENT_TYPE_HEADER_FIELD_HPP 
