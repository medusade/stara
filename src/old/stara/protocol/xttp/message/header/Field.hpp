///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 12/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELD_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELD_HPP

#include "stara/protocol/xttp/message/Line.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace message {
namespace header {

typedef message::LineTImplements FieldTImplements;
typedef message::Line FieldTExtends;
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
    FieldT(const String& s)
    : Extends(s) {
        Separate();
    }
    FieldT(const char* chars, size_t length)
    : Extends(chars, length) {
        Separate();
    }
    FieldT(const char* chars)
    : Extends(chars) {
        Separate();
    }
    FieldT(const FieldT& copy)
    : Extends(copy),
      m_name(copy.Name()),
      m_value(copy.Value()) {
    }
    FieldT() {
    }
    virtual ~FieldT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = true;
        this->clear();
        if ((m_name.has_chars())) {
            this->assign(m_name);
            this->append(':');
            this->append(m_value);
        }
        return success;
    }
    virtual bool Separate() {
        bool success = true;
        const char* chars = 0;
        size_t length = 0;

        SetDefaults();
        if ((chars = this->has_chars(length))) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, name, value;

            for (part = &name; chars != end; ++chars) {
                if (':' != (c = *chars)) {
                    if (' ' != (c)) {
                        part->append(&c, 1);
                    } else {
                        if ((part->has_chars())) {
                            part->append(&c, 1);
                        }
                    }
                } else {
                    if (part != &name) {
                        part->append(&c, 1);
                    } else {
                        if (name.has_chars()) {
                            // ?':'
                            part = &value;
                        } else {
                            // ':'
                            return false;
                        }
                    }
                }
            }
            if ((name.has_chars())) {
                m_name.Set(name);
                m_value.Set(value);
            } else {
                return false;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FieldT& SetDefault() {
        SetDefaults();
        Combine();
        return *this;
    }
    virtual FieldT& SetDefaults() {
        m_name.clear();
        m_value.clear();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FieldT& Set(const String& name, const String& value) {
        const char* chars = 0;
        size_t length = 0;
        if ((chars = name.has_chars(length))) {
            m_name.assign(chars, length);
            m_value.assign(value);
            Combine();
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message::Part& SetName(const String& s) {
        const char* chars = 0;
        size_t length = 0;
        if ((chars = s.has_chars(length))) {
            m_name.assign(chars, length);
            Combine();
        }
        return m_name;
    }
    virtual message::Part& SetName(const char* chars, size_t length) {
        if ((chars) && (0 < length)) {
            m_name.assign(chars, length);
            Combine();
        }
        return m_name;
    }
    virtual message::Part& SetName(const char* chars) {
        if ((chars) && (chars[0])) {
            m_name.assign(chars);
            Combine();
        }
        return m_name;
    }
    virtual const message::Part& Name() const {
        return m_name;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message::Part& SetValue(const String& s) {
        m_value.assign(s);
        Combine();
        return m_value;
    }
    virtual message::Part& SetValue(const char* chars, size_t length) {
        m_value.assign(chars, length);
        Combine();
        return m_value;
    }
    virtual message::Part& SetValue(const char* chars) {
        m_value.assign(chars);
        Combine();
        return m_value;
    }
    virtual const message::Part& Value() const {
        return m_value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    message::Part m_name, m_value;
};
typedef FieldT<> Field;

} // namespace header
} // namespace message 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELD_HPP 
