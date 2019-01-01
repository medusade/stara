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
///   Date: 3/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_HTTP_FORM_FIELDS_HPP
#define _STARA_PROTOCOL_HTTP_FORM_FIELDS_HPP

#include "stara/protocol/http/form/FieldsSignals.hpp"
#include "stara/protocol/http/form/Field.hpp"
#include "crono/io/Logger.hpp"
#include <list>

namespace stara {
namespace protocol {
namespace http {
namespace form {

typedef FieldsSignals FieldsTSignalsImplements;
typedef xttp::message::PartTImplements FieldsTImplements;
typedef xttp::message::Part FieldsTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FieldsT
///////////////////////////////////////////////////////////////////////
template
<class TSignalsImplements = FieldsTSignalsImplements,
 class TImplements = FieldsTImplements,
 class TExtends = FieldsTExtends>

class _EXPORT_CLASS FieldsT
: virtual public TSignalsImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TSignalsImplements SignalsImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef std::list<Field*> List;
    typedef List::const_iterator const_iterator;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldsT(const String& s)
    : Extends(s), m_signalsForwardTo(0), m_field(0) {
        Separate();
    }
    FieldsT(const char* chars, size_t length)
    : Extends(chars, length), m_signalsForwardTo(0), m_field(0) {
        Separate();
    }
    FieldsT(const char* chars)
    : Extends(chars), m_signalsForwardTo(0), m_field(0) {
        Separate();
    }
    FieldsT(const FieldsT& copy)
    : Extends(copy), m_signalsForwardTo(0), m_field(0) {
    }
    FieldsT()
    : m_signalsForwardTo(0), m_field(0) {
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
                if ('&' != (c = *chars)) {
                    last = chars;
                } else {
                    if (last) {
                        if ((field = AddField(first, (last - first) + 1))) {
                            OnAddField(*field);
                            first = ++last;
                            last = 0;
                        } else {
                            success = false;
                            break;
                        }
                    } else {
                        success = false;
                        break;
                    }
                }
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = true;
        const char* chars = 0;
        Field* field = 0;
        SetDefault();
        do {
            CRONO_LOG_DEBUG("ReadField(count, c, reader)...");
            if ((field = ReadField(count, c, reader))) {
                CRONO_LOG_DEBUG("...field = \"" << field->chars() << "\" on ReadField(count, c, reader)");

                if ((chars = field->has_chars())) {
                    m_list.push_back(field);
                    OnAddField(*field);
                } else {
                    FreeField(field);
                    break;
                }
            }
        } while ((field) && ('&' == c));
        return success;
    }
    virtual bool Write(ssize_t& count, io::CharWriter& writer) {
        bool success = true;
        const char* chars = 0;
        size_t length = 0;
        ssize_t amount = 0;
        Field* field = 0;
        List::const_iterator i, begin, end;

        for (count = 0, begin = m_list.begin(),
             end = m_list.end(), i = begin; i != end; ++i) {

            if ((field = (*i))) {

                if ((chars = field->has_chars(length))) {

                    if (i != begin) {
                        CRONO_LOG_DEBUG("writer.Write(\"&\")...");
                        if (1 <= (amount = writer.Write("&"))) {
                            CRONO_LOG_DEBUG("...amount = " << amount << " on writer.Write(\"&\")");
                            count += amount;
                        } else {
                            success = false;
                            break;
                        }
                    }
                    CRONO_LOG_DEBUG("writer.Write(chars, length) with chars = \"" << chars << "\"");
                    if (length <= (amount = writer.Write(chars, length))) {
                        CRONO_LOG_DEBUG("...amount = " << amount << " on writer.Write(chars, length) with chars = \"" << chars << "\"");
                        count += amount;
                        continue;
                    }
                }
            }
            success = false;
            break;
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
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnAddField(const Field& field) {
        this->OnFieldsSignal_AddField(field);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SignalsImplements* ForwardFormFieldsSignalsTo(SignalsImplements* to) {
        SignalsImplements* old_signalsForwardTo = m_signalsForwardTo;
        m_signalsForwardTo = to;
        return old_signalsForwardTo;
    }
    virtual SignalsImplements* FormFieldsSignalsForwardTo() const {
        return m_signalsForwardTo;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SignalsImplements* m_signalsForwardTo;
    Field* m_field;
    List m_list;
};
typedef FieldsT<> Fields;

} // namespace form
} // namespace http 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_HTTP_FORM_FIELDS_HPP 
