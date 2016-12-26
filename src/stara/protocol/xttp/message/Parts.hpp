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
///   File: Parts.hpp
///
/// Author: $author$
///   Date: 12/25/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_PARTS_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_PARTS_HPP

#include "stara/protocol/xttp/message/header/Fields.hpp"

namespace stara {
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
        if ((chars = m_line.has_chars())) {
            const header::Field* h = 0;
            header::Fields::const_iterator i;
            this->assignl(chars, "\r\n", NULL);
            if ((h = m_headers.First(i))) {
                do {
                    if ((chars = h->has_chars())) {
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
        if ((chars = this->has_chars(length))) {
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
                                    m_headers.OnField(*field);
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
        SetDefault();
        if ((m_line.Read(count, c, reader))) {
            if ((m_headers.Read(count, c, reader))) {
                if ((Combine())) {
                    success = true;
                }
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
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_PARTS_HPP 
