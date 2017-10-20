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
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_FORM_FIELD_HPP
#define _XOS_PROTOCOL_HTTP_FORM_FIELD_HPP

#include "xos/base/String.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace form {

///////////////////////////////////////////////////////////////////////
///  Class: FieldT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ImplementBase, class TExtends = Base>

class _EXPORT_CLASS FieldT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef String string_t;
    typedef char char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldT(const string_t& name, const string_t& value)
    : m_name(name), m_value(value) {
    }
    FieldT(const char_t* name, const char_t* value)
    : m_name(name), m_value(value) {
    }
    FieldT(const FieldT& copy)
    : m_name(copy.m_name), m_value(copy.m_value) {
    }
    FieldT() {
    }
    virtual ~FieldT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& SetName(const char_t* chars, size_t length) {
        m_name.Assign(chars, length);
        return m_name;
    }
    virtual string_t& SetName(const char_t* chars) {
        m_name.Assign(chars);
        return m_name;
    }
    virtual string_t& Name() const {
        return ((string_t&)m_name);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& SetValue(const char_t* chars, size_t length) {
        m_value.Assign(chars, length);
        return m_value;
    }
    virtual string_t& SetValue(const char_t* chars) {
        m_value.Assign(chars);
        return m_value;
    }
    virtual string_t& Value() const {
        return ((string_t&)m_value);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator == (const FieldT& to) const {
        return !((this) != (&to));
    }
    virtual bool operator < (const FieldT& to) const {
        return ((this) < (&to));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t m_name, m_value;
};
typedef FieldT<> Field;

} // namespace form
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_FORM_FIELD_HPP
