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
///   File: Fields.hpp
///
/// Author: $author$
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_URL_ENCODED_FORM_FIELDS_HPP
#define _XOS_PROTOCOL_HTTP_URL_ENCODED_FORM_FIELDS_HPP

#include "xos/protocol/http/url/encoded/Reader.hpp"
#include "xos/protocol/http/form/Fields.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace url {
namespace encoded {
namespace form {

typedef http::form::FieldsTImplements FieldsTImplements;
typedef http::form::Fields FieldsTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FieldsT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = FieldsTImplements, class TExtends = FieldsTExtends>

class _EXPORT_CLASS FieldsT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldsT(const String& s)
    : Extends(s) {
    }
    FieldsT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    FieldsT(const char* chars)
    : Extends(chars) {
    }
    FieldsT(const FieldsT& copy)
    : Extends(copy) {
    }
    FieldsT() {
    }
    virtual ~FieldsT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        url::encoded::CharReader encodedReader(reader);
        bool success = Extends::Read(count, c, encodedReader);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FieldsT<> Fields;

} // namespace form
} // namespace encoded 
} // namespace url 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_URL_ENCODED_FORM_FIELDS_HPP 
