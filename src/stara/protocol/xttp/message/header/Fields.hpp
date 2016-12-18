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
///   File: Fields.hpp
///
/// Author: $author$
///   Date: 12/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELDS_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELDS_HPP

#include "stara/protocol/xttp/message/header/Field.hpp"
#include <list>

namespace stara {
namespace protocol {
namespace xttp {
namespace message {
namespace header {

typedef message::PartTImplements FieldsTImplements;
typedef message::Part FieldsTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FieldsT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = FieldsTImplements,
 class TExtends = FieldsTExtends>

class _EXPORT_CLASS FieldsT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef std::list<Field*> List;
    typedef List::const_iterator const_iterator;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldsT(const char* chars, size_t length)
    : Extends(chars, length), m_field(0), m_contentLength(0) {
        Separate();
    }
    FieldsT(const char* chars)
    : Extends(chars), m_field(0), m_contentLength(0) {
        Separate();
    }
    FieldsT(const FieldsT& copy)
    : Extends(copy), m_field(0), m_contentLength(0) {
    }
    FieldsT(): m_field(0), m_contentLength(0) {
    }
    virtual ~FieldsT() {
        ClearList();
        FreeField();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = true;
        this->clear();
        return success;
    }
    virtual bool Separate() {
        bool success = true;
        const char* chars = 0;
        size_t length = 0;

        SetDefaults();
        if ((chars = this->has_chars(length))) {
            const char *end = chars + length, *first = chars, *last = 0;
            Field* field = 0;
            char c = 0;

            for (; chars != end; ++chars) {
                if ('\r' != (c = *chars)) {
                    if ('\n' != (c)) {
                        last = chars;
                    } else {
                        if (last) {
                            if ((field = AddField(first, (last - first) + 1))) {
                                OnField(*field);
                            } else {
                                success = false;
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                } else {
                }
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = true;
        Field* field = 0;
        SetDefault();
        while ((field = ReadField(count, c, reader))) {
            if ((field->has_chars())) {
                m_list.push_back(field);
                OnField(*field);
            } else {
                FreeField(field);
                break;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FieldsT& SetDefault() {
        SetDefaults();
        Combine();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const Field* First(const_iterator& at) const {
        if ((at = m_list.begin()) != m_list.end()) {
            return (*at);
        }
        return 0;
    }
    virtual const Field* Next(const_iterator& at) const {
        if ((at != m_list.end())) {
            if ((++at != m_list.end())) {
                return (*at);
            }
        }
        return 0;
    }
    virtual const Field* Prev(const_iterator& at) const {
        if ((at != m_list.begin())) {
            return (*--at);
        }
        return 0;
    }
    virtual size_t ContentLength() const {
        return m_contentLength;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Field* ReadField(ssize_t& count, char& c, io::CharReader& reader) {
        Field* field = 0;
        if ((field = GetField())) {
            if ((field->Read(count, c, reader))) {
                return field;
            }
            FreeField(field);
        }
        return 0;
    }
    virtual Field* AddField(const char *chars, size_t length) {
        if ((chars) && (length)) {
            Field* field = 0;
            if ((field = GetField())) {
                field->assign(chars, length);
                if ((field->Separate())) {
                    m_list.push_back(field);
                    return field;
                }
                FreeField(field);
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Field* GetField() {
        Field* field = 0;
        if (!(field = m_field)) {
            field = new Field;
        } else {
            m_field = 0;
        }
        return field;
    }
    virtual void FreeField(Field* field = 0) {
        if ((field)) {
            if ((m_field)) {
                if ((m_field != field)) {
                    delete m_field;
                    m_field = field;
                }
            } else {
                m_field = field;
            }
        } else {
            if ((m_field)) {
                delete m_field;
                m_field = 0;
            }
        }
    }
    virtual void ClearList() {
        for (Field* field = 0; !m_list.empty(); m_list.pop_front()) {
            if ((field = m_list.front())) {
                delete field;
            }
        }
    }
    virtual FieldsT& SetDefaults() {
        ClearList();
        FreeField();
        m_contentLength = 0;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnField(const Field& field) {
        if (!(field.Name().case_compare("Content-Length"))) {
            std::stringstream ss(field.Value());
            size_t value = 0;
            if (0 < (ss >> value)) {
                m_contentLength = value;
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t m_contentLength;
    Field* m_field;
    List m_list;
};
typedef FieldsT<> Fields;

} // namespace header
} // namespace message 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELDS_HPP 
