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
///   Date: 9/25/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_MESSAGE_FORM_FIELDS_HPP
#define _XOS_PROTOCOL_HTTP_MESSAGE_FORM_FIELDS_HPP

#include "xos/protocol/http/message/form/FieldsSignals.hpp"
#include "xos/protocol/http/form/Fields.hpp"
#include "xos/logger/Interface.hpp"

#include <list>

namespace xos {
namespace protocol {
namespace http {
namespace message {
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

    typedef ::std::list<Field*> List;
    typedef List::const_iterator const_iterator;
    typedef List list_t;
    typedef Field field_t;
    typedef String string_t;

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
    const char_t* FindValue
    (const string_t& name, const field_t* from = 0) const {
        return FindValue(name.Chars(), from);
    }
    const char_t* FindValue
    (const char_t* name, const field_t* from = 0) const {
        field_t* f = 0;
        if ((f = Find(name, from))) {
            return f->Value().HasChars();
        }
        return 0;
    }
    const char_t* FindValue
    (const char_t** names, const field_t* from = 0) const {
        field_t* f = 0;
        if ((f = Find(names, from))) {
            return f->Value().HasChars();
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    field_t* Find(const string_t& name, const field_t* from = 0) const {
        return Find(name.Chars(), from);
    }
    field_t* Find(const char_t* name, const field_t* from = 0) const {
        const const_iterator begin = this->Begin();
        const const_iterator end = this->End();

        for (const_iterator i = begin; i != end; ++i) {
            const field_t* found = 0;

            if ((found = (*i))) {
                if ((from)) {
                    if (from == found) {
                        from = 0;
                    }
                } else {
                    if (!(found->Name().Compare(name))) {
                        return ((field_t*)found);
                    }
                }
            }
        }
        return 0;
    }
    field_t* Find(const char_t** names, const field_t* from = 0) const {
        if ((names) && (names[0])) {
            const const_iterator begin = this->Begin();
            const const_iterator end = this->End();

            for (const_iterator i = begin; i != end; ++i) {
                const field_t* found = 0;

                if ((found = (*i))) {
                    if ((from)) {
                        if (from == found) {
                            from = 0;
                        }
                    } else {
                        size_t n = 0;

                        for (const char_t* name = names[n]; name; name = names[++n]) {
                            if (!(found->Name().Compare(name))) {
                                return ((field_t*)found);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    field_t* Find(const_iterator& at) const {
        if (at != (this->End())) {
            field_t* found = 0;
            if ((found = (*at))) {
                return found;
            }
        }
        return 0;
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
        if ((chars = this->HasChars(length))) {
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
        SetDefault();
        return ReadMore(count, c, reader);
    }
    virtual bool ReadMore(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = true;
        const char* chars = 0;
        Field* field = 0;

        do {
            XOS_LOG_DEBUG("ReadField(count, c, reader)...");
            if ((field = ReadField(count, c, reader))) {
                XOS_LOG_DEBUG("...field = \"" << field->chars() << "\" on ReadField(count, c, reader)");

                if ((chars = field->HasChars())) {
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

                if ((chars = field->HasChars(length))) {

                    if (i != begin) {
                        XOS_LOG_DEBUG("writer.Write(\"&\")...");
                        if (1 <= (amount = writer.Write("&"))) {
                            XOS_LOG_DEBUG("...amount = " << amount << " on writer.Write(\"&\")");
                            count += amount;
                        } else {
                            success = false;
                            break;
                        }
                    }
                    XOS_LOG_DEBUG("writer.Write(chars, length) with chars = \"" << chars << "\"");
                    if (length <= (amount = writer.Write(chars, length))) {
                        XOS_LOG_DEBUG("...amount = " << amount << " on writer.Write(chars, length) with chars = \"" << chars << "\"");
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
    virtual const_iterator Begin() const {
        return m_list.begin();
    }
    virtual const_iterator End() const {
        return m_list.end();
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
    virtual FieldsT& Clear() {
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

typedef http::form::WriterT<Field, Fields> Writer;

} // namespace form
} // namespace message 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_MESSAGE_FORM_FIELDS_HPP 
