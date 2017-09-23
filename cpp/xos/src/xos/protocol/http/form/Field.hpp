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

#include "xos/protocol/xttp/message/Part.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace form {

typedef xttp::message::PartTImplements FieldTImplements;
typedef xttp::message::Part FieldTExtends;
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

    typedef xttp::message::Part Part;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldT(const String& name, const String& value)
    : m_name(name), m_value(value) {
        Combine();
    }
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
        if ((m_name.HasChars())) {
            this->Assign(m_name);
            this->Append("=");
            this->Append(m_value);
        }
        return success;
    }
    virtual bool Separate() {
        bool success = true;
        const char* chars = 0;
        size_t length = 0;

        SetDefaults();
        if ((chars = this->HasChars(length))) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, name, value;

            for (part = &name; chars != end; ++chars) {
                if ('=' != (c = *chars)) {
                    part->Append(&c, 1);
                } else {
                    if (part != &name) {
                        part->Append(&c, 1);
                    } else {
                        if (name.HasChars()) {
                            // ?'='
                            part = &value;
                        } else {
                            // '='
                            return false;
                        }
                    }
                }
            }
            if ((name.HasChars())) {
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
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        ssize_t amount = 0;
        String chars;

        SetDefault();
        do {
            if (0 < (amount = reader.Read(&c, 1))) {
                count += amount;
                if (('&' != c)) {
                    chars.Append(&c, 1);
                } else {
                    success = this->Set(chars);
                    break;
                }
            } else {
                if (0 > (amount)) {
                    count = amount;
                    break;
                } else {
                    success = this->Set(chars);
                }
            }
        } while (0 < amount);
        return success;
    }
    virtual bool Write(ssize_t& count, io::CharWriter& writer) {
        bool success = false;
        const char* chars = 0;
        size_t length = 0;
        ssize_t amount = 0;

        if ((chars = this->HasChars(length))) {
            if (length <= (amount = writer.Write(chars, length))) {
                count = amount;
                success = true;
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
    virtual Part& SetName(const String& to) {
        m_name.Set(to);
        Combine();
        return m_name;
    }
    virtual const Part& Name() const {
        return m_name;
    }
    virtual Part& SetValue(const String& to) {
        m_value.Set(to);
        Combine();
        return m_value;
    }
    virtual const Part& Value() const {
        return m_value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Part m_name, m_value;
};
typedef FieldT<> Field;

} // namespace form
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_FORM_FIELD_HPP
