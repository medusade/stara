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
///   File: Message.hpp
///
/// Author: $author$
///   Date: 12/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_RESPONSE_MESSAGE_HPP
#define _STARA_PROTOCOL_XTTP_RESPONSE_MESSAGE_HPP

#include "stara/protocol/xttp/response/status/Line.hpp"
#include "stara/protocol/xttp/message/header/Fields.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace response {

typedef message::PartTImplements MessageTImplements;
typedef message::Part MessageTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MessageT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MessageTImplements, class TExtends = MessageTExtends>

class _EXPORT_CLASS MessageT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MessageT(const char* chars, size_t length)
    : Extends(chars, length) {
        Separate();
    }
    MessageT(const char* chars)
    : Extends(chars) {
        Separate();
    }
    MessageT(const MessageT& copy)
    : Extends(copy) {
    }
    MessageT() {
        Combine();
    }
    virtual ~MessageT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = false;
        const char* chars = 0;
        const message::header::Field* h = 0;
        message::header::Fields::const_iterator i;
        this->clear();
        if ((chars = m_line.has_chars())) {
            this->appendl(chars, "\r\n", NULL);
            if ((h = m_headers.First(i))) {
                do {
                    if ((chars = h->has_chars())) {
                        this->appendl(chars, "\r\n", NULL);
                    }
                } while ((h = m_headers.Next(i)));
            }
            this->appendl("\r\n", NULL);
            success = true;
        }
        return success;
    }
    virtual bool Separate() {
        bool success = true;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Set(const String& to) {
        bool success = true;
        this->assign(to);
        success = Separate();
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual MessageT& SetDefault() {
        SetDefaults();
        Combine();
        return *this;
    }
    virtual MessageT& SetDefaults() {
        m_line.SetDefault();
        m_headers.SetDefault();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    status::Line m_line;
    message::header::Fields m_headers;
};
typedef MessageT<> Message;

} // namespace response
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_RESPONSE_MESSAGE_HPP 
