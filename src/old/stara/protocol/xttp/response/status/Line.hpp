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
///   File: Line.hpp
///
/// Author: $author$
///   Date: 12/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_RESPONSE_STATUS_LINE_HPP
#define _STARA_PROTOCOL_XTTP_RESPONSE_STATUS_LINE_HPP

#include "stara/protocol/xttp/protocol/Identifier.hpp"
#include "stara/protocol/xttp/response/status/Code.hpp"
#include "stara/protocol/xttp/response/status/Reason.hpp"
#include "stara/protocol/xttp/message/Line.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace response {
namespace status {

typedef message::LineTImplements LineTImplements;
typedef message::Line LineTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LineT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = LineTImplements, class TExtends = LineTExtends>

class _EXPORT_CLASS LineT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LineT(const char* chars, size_t length)
    : Extends(chars, length) {
        Separate();
    }
    LineT(const char* chars)
    : Extends(chars) {
        Separate();
    }
    LineT(const LineT& copy)
    : Extends(copy),
      m_protocol(copy.m_protocol),
      m_code(copy.m_code),
      m_reason(copy.m_reason) {
    }
    LineT() {
        Combine();
    }
    virtual ~LineT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        const char* chars = 0;
        if ((chars = m_protocol.has_chars())) {
            this->assignl(chars, " ", NULL);
            if ((chars = m_code.has_chars())) {
                this->appendl(chars, " ", NULL);
                if ((chars = m_reason.has_chars())) {
                    this->appendl(chars, NULL);
                }
                return true;
            }
        }
        this->clear();
        return false;
    }
    virtual bool Separate() {
        bool success = true;
        const char* chars = 0;
        size_t length = 0;

        SetDefaults();

        if ((chars = this->has_chars(length))) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, protocol, code, reason;

            for (part = &protocol; chars != end; ++chars) {
                if (' ' != (c = *chars)) {
                    part->append(&c, 1);
                } else {
                    if (part == &protocol) {
                        if (protocol.has_chars()) {
                            // ?' '
                            part = &code;
                        } else {
                            // ' '
                            return false;
                        }
                    } else {
                        if (part != &reason) {
                            if (code.has_chars()) {
                                // ?' '?' '
                                part = &reason;
                            } else {
                                // ?' '' '
                                return false;
                            }
                        } else {
                            // ?' '?'/'*' '
                            return false;
                        }
                    }
                }
            }
            if ((protocol.has_chars())
                && (code.has_chars())
                && (reason.has_chars())) {
                m_protocol.Set(protocol);
                m_code.Set(code);
                m_reason.Set(reason);
                success = true;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual LineT& SetDefault() {
        SetDefaults();
        Combine();
        return *this;
    }
    virtual LineT& SetDefaults() {
        m_protocol.SetDefault();
        m_code.SetDefault();
        m_reason.SetDefault();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    protocol::Identifier m_protocol;
    Code m_code;
    Reason m_reason;
};
typedef LineT<> Line;

} // namespace status 
} // namespace response 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_RESPONSE_STATUS_LINE_HPP 
