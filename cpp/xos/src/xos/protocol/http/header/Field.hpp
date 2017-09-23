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
#ifndef _XOS_PROTOCOL_HTTP_HEADER_FIELD_HPP
#define _XOS_PROTOCOL_HTTP_HEADER_FIELD_HPP

#include "xos/protocol/http/message/header/field/Name.hpp"
#include "xos/protocol/http/message/header/field/Which.hpp"
#include "xos/protocol/xttp/message/header/Field.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace header {

typedef xttp::message::header::FieldTImplements FieldTImplements;
typedef xttp::message::header::Field FieldTExtends;
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
    FieldT(message::header::field::Which which, const String& value) {
        this->SetName(message::header::field::Name::OfWhich(which));
        this->SetValue(value);
    }
    FieldT(message::header::field::Which which, const char* value) {
        this->SetName(message::header::field::Name::OfWhich(which));
        this->SetValue(value);
    }
    FieldT(message::header::field::Which which) {
        this->SetName(message::header::field::Name::OfWhich(which));
    }
    FieldT(const FieldT& copy): Extends(copy) {
    }
    FieldT() {
    }
    virtual ~FieldT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FieldT<> Field;

} // namespace header
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_HEADER_FIELD_HPP 
