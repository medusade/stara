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
#ifndef _XOS_PROTOCOL_HTTP_FORM_FIELDS_HPP
#define _XOS_PROTOCOL_HTTP_FORM_FIELDS_HPP

#include "xos/protocol/http/form/FieldsSignals.hpp"
#include "xos/protocol/http/form/Field.hpp"
#include "xos/io/Reader.hpp"
#include "xos/io/Writer.hpp"
#include "xos/logger/Interface.hpp"

#include <list>

namespace xos {
namespace protocol {
namespace http {
namespace form {

///////////////////////////////////////////////////////////////////////
///  Class: FieldsT
///////////////////////////////////////////////////////////////////////
template
<class TField = Field,
 class TSignals = FieldsSignalsT<TField>,
 class TList = ::std::list<TField>,
 class TImplements = TSignals, class TExtends = TList>

class _EXPORT_CLASS FieldsT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::const_iterator const_iterator;
    typedef typename Extends::iterator iterator;
    typedef typename TField::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef TField field_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FieldsT(const FieldsT& copy): Extends(copy) {
    }
    FieldsT() {
    }
    virtual ~FieldsT() {
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
        const const_iterator begin = this->begin();
        const const_iterator end = this->end();
        for (const_iterator i = begin; i != end; ++i) {
            const field_t& found = (*i);
            if ((from)) {
                if (from == &found) {
                    from = 0;
                }
            } else {
                if (!(found.Name().compare(name))) {
                    return ((field_t*)&found);
                }
            }
        }
        return 0;
    }
    field_t* Find(const char_t** names, const field_t* from = 0) const {
        if ((names) && (names[0])) {
            const const_iterator begin = this->begin();
            const const_iterator end = this->end();
            for (const_iterator i = begin; i != end; ++i) {
                const field_t& found = (*i);
                if ((from)) {
                    if (from == &found) {
                        from = 0;
                    }
                } else {
                    size_t n = 0;
                    for (const char_t* name = names[n]; name; name = names[++n]) {
                        if (!(found.Name().compare(name))) {
                            return ((field_t*)&found);
                        }
                    }
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FieldsT<> Fields;

///////////////////////////////////////////////////////////////////////
///  Class: ReaderT
///////////////////////////////////////////////////////////////////////
template
<class TField = Field,
 class TFields = Fields,
 class TReader = io::CharReader,
 class TImplements = ImplementBase, class TExtends = Base>

class _EXPORT_CLASS ReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef ReaderT Derives;

    typedef TFields fields_t;
    typedef TField field_t;
    typedef TReader reader_t;
    typedef typename TField::string_t string_t;
    typedef typename TReader::char_t char_t;
    typedef typename TReader::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ReaderT(): on_(0) {
    }
    virtual ~ReaderT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, reader_t& reader, fields_t& fields) {
        fields.Free();
        return ReadMore(count, reader, fields);
    }
    virtual bool ReadMore
    (ssize_t& count, reader_t& reader, fields_t& fields) {
        bool success = false;

        if ((success = on_begin(fields))) {
            ssize_t amount = 0;
            char_t c = 0;

            do {
                if (0 < (amount = reader.Read(&c,1 ))) {
                    if ((on(fields, c))) {
                        count += amount;
                        continue;
                    }
                } else {
                    count = amount;
                    success = false;
                }
                break;
            } while (0 < (amount));

            if (!(on_end(fields))) {
                success = false;
            }
        }
        return success;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_begin(fields_t& fields) {
        name_.Clear();
        value_.Clear();
        on_ = &Derives::on_name;
        return true;
    }
    virtual bool on_end(fields_t& fields) {
        name_.Clear();
        value_.Clear();
        on_ = 0;
        return true;
    }
    virtual bool on_next(fields_t& fields) {
        name_.Clear();
        value_.Clear();
        on_ = &Derives::on_name;
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on(fields_t& fields, const char_t& c) {
        bool success = false;
        if ((on_)) {
            success = (this->*on_)(fields, c);
        }
        return success;
    }
    virtual bool on_name(fields_t& fields, const char_t& c) {
        bool success = false;
        return success;
    }
    virtual bool on_value(fields_t& fields, const char_t& c) {
        bool success = false;
        return success;
    }
    virtual bool on_no_name(fields_t& fields, const char_t& c) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    static const char_t eq_ = ((char_t)'=');
    static const char_t cr_ = ((char_t)'\r');
    static const char_t lf_ = ((char_t)'\n');
    void (Derives::*on_)(fields_t& fields, const char_t& c);
    string_t name_, value_;
};
typedef ReaderT<> Reader;

///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template
<class TField = Field,
 class TFields = Fields,
 class TWriter = io::CharWriter,
 class TImplements = ImplementBase, class TExtends = Base>

class _EXPORT_CLASS WriterT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef WriterT Derives;

    typedef TFields fields_t;
    typedef typename TFields::const_iterator const_iterator;

    typedef TField field_t;
    typedef TWriter writer_t;
    typedef typename TWriter::char_t char_t;
    typedef typename TWriter::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WriterT() {
    }
    virtual ~WriterT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Write(ssize_t& count, writer_t& writer, fields_t& fields) {
        bool success = true;
        static const char_t eq = ((char_t)'=');
        const char_t *chars = 0;
        size_t length = 0;
        ssize_t amount = 0;
        const_iterator e, i;

        for (count = 0, e = fields.End(), i = fields.Begin(); i != e; ++i) {
            const field_t* f = fields.Find(i);

            if ((f) && (chars = f->Name().HasChars(length))) {

                if (0 < (amount = writer.Write(chars, length))) {
                    count += amount;
                    if (0 < (amount = writer.Write(&eq, 1))) {
                        count += amount;
                    } else {
                        count = amount;
                        success = false;
                        break;
                    }
                } else {
                    count = amount;
                    success = false;
                    break;
                }
                if ((chars = f->Value().HasChars(length))) {
                    if (0 < (amount = writer.Write(chars, length))) {
                        count += amount;
                    } else {
                        count = amount;
                        success = false;
                        break;
                    }
                }
                if ((WriteLn(amount, writer))) {
                    count += amount;
                } else {
                    count = amount;
                    success = false;
                    break;
                }
                continue;
            }
            success = false;
            break;
        }
        if ((success)) {
            if ((WriteLn(amount, writer))) {
                count += amount;
            } else {
                count = amount;
                success = false;
            }
        }
        return success;
    }
    virtual bool WriteLn(ssize_t& count, writer_t& writer) {
        bool success = true;
        static const char_t cr = ((char_t)'\r');
        static const char_t lf = ((char_t)'\n');
        ssize_t amount = 0;

        if (0 < (count = writer.Write(&cr, 1))) {

            if (0 < (amount = writer.Write(&lf, 1))) {
                count += amount;
            } else {
                count = amount;
                success = false;
            }
        } else {
            success = false;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace form
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_FORM_FIELDS_HPP
