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
///   File: Parts.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_MESSAGE_PARTS_HPP
#define _XOS_PROTOCOL_XTTP_MESSAGE_PARTS_HPP

#include "xos/protocol/xttp/message/header/Fields.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace message {

typedef message::PartTImplements PartsTImplements;
typedef message::Part PartsTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: PartsT
///////////////////////////////////////////////////////////////////////
template
<class TLine = message::Line,
 class TImplements = PartsTImplements, class TExtends = PartsTExtends>

class _EXPORT_CLASS PartsT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PartsT(const String& s)
    : Extends(s) {
        Separate();
    }
    PartsT(const char* chars, size_t length)
    : Extends(chars, length) {
        Separate();
    }
    PartsT(const char* chars)
    : Extends(chars) {
        Separate();
    }
    PartsT(const PartsT& copy)
    : Extends(copy),
      m_line(copy.m_line),
      m_headers(copy.m_headers) {
    }
    PartsT() {
        Combine();
    }
    virtual ~PartsT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        const char* chars = 0;
        if ((chars = m_line.HasChars())) {
            const header::Field* h = 0;
            header::Fields::const_iterator i;
            this->assignl(chars, "\r\n", NULL);
            if ((h = m_headers.First(i))) {
                do {
                    if ((chars = h->HasChars())) {
                        this->appendl(chars, "\r\n", NULL);
                    }
                } while ((h = m_headers.Next(i)));
            }
            this->appendl("\r\n", NULL);
            return true;
        }
        this->clear();
        return false;
    }
    virtual bool Separate() {
        bool success = false;
        const char* chars = 0;
        size_t length = 0;

        SetDefaults();
        if ((chars = this->HasChars(length))) {
            const char *end = chars + length, *first = chars, *last = 0;
            header::Field* field = 0;
            char c = 0;

            for (bool line = false; chars != end; ++chars) {
                if ('\r' != (c = *chars)) {
                    if ('\n' != (c)) {
                        last = chars;
                    } else {
                        if (last) {
                            if (line) {
                                if ((field = m_headers.AddField(first, (last - first) + 1))) {
                                    m_headers.OnAddField(*field);
                                } else {
                                    SetDefaults();
                                    return false;
                                }
                            } else {
                                if ((line = m_line.Set(first, (last - first) + 1))) {
                                    success = true;
                                } else {
                                    SetDefaults();
                                    return false;
                                }
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
        bool success = false;
        ssize_t amount = 0;
        SetDefault();

        XOS_LOG_DEBUG("m_line.Read(count, c, reader)...");
        if ((m_line.Read(amount, c, reader))) {
            XOS_LOG_DEBUG("...\"" << m_line << "\" = m_line.Read(count, c, reader)");

            count = amount;
            if ((m_headers.Read(amount, c, reader))) {
                count += amount;
                if ((Combine())) {
                    success = true;
                }
            }
        }
        return success;
    }
    virtual bool Write(ssize_t& count, io::CharWriter& writer) {
        bool success = false;
        ssize_t amount = 0;

        XOS_LOG_DEBUG("m_line.Write(amount, writer) with line = \"" << m_line << "\"...");
        if ((m_line.Write(amount, writer))) {
            XOS_LOG_DEBUG("...amount = " << amount << " on m_line.Write(amount, writer) with line = \"" << m_line << "\"...");

            count = amount;
            if ((m_headers.Write(amount, writer))) {
                count += amount;
                success = true;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual PartsT& SetDefault() {
        SetDefaults();
        Combine();
        return *this;
    }
    virtual PartsT& SetDefaults() {
        m_line.SetDefault();
        m_headers.SetDefault();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual header::Field* AddHeaderField
    (const String& name, const String& value) {
        header::Field* f = 0;
        if ((f = m_headers.AddField(name, value))) {
            return f;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t SetContentLength(size_t to) {
        return m_headers.SetContentLength(to);
    }
    virtual size_t ContentLength() const {
        return m_headers.ContentLength();
    }
    virtual const TLine& Line() const {
        return m_line;
    }
    virtual const header::Fields& Headers() const {
        return m_headers;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TLine m_line;
    header::Fields m_headers;
};
typedef PartsT<> Parts;

} // namespace message
} // namespace xttp 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_MESSAGE_PARTS_HPP 
