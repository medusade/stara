///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_REQUEST_LINE_HPP
#define _STARA_PROTOCOL_XTTP_REQUEST_LINE_HPP

#include "stara/protocol/xttp/protocol/Identifier.hpp"
#include "stara/protocol/xttp/request/Parameters.hpp"
#include "stara/protocol/xttp/request/Method.hpp"
#include "stara/protocol/xttp/message/Line.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace request {

typedef message::LineTImplements LineTImplements;
typedef message::Line LineTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LineT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = LineTImplements,
 class TExtends = LineTExtends>

class _EXPORT_CLASS LineT: virtual public TImplements, public TExtends {
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
    : Extends(copy) {
    }
    LineT() {
        Combine();
    }
    virtual ~LineT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        const char *method = 0, *parameters = 0, *protocol = 0;
        if ((method = m_method.has_chars())
            && (parameters = m_parameters.has_chars())
            && (protocol = m_protocol.has_chars())) {
            this->assignl(method, " ", parameters, " ", protocol, NULL);
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
            char c = 0;
            const char* end = chars + length;
            String *part = 0, method, parameters, protocol;

            for (part = &method; chars != end; ++chars) {
                if (' ' != (c = *chars)) {
                    part->append(&c, 1);
                } else {
                    if (part == &method) {
                        if (method.has_chars()) {
                            // ?' '
                            part = &parameters;
                        } else {
                            // ' '
                            return false;
                        }
                    } else {
                        if (part != &protocol) {
                            if (parameters.has_chars()) {
                                // ?' '?' '
                                part = &protocol;
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
            if ((method.has_chars())
                && (parameters.has_chars())
                && (protocol.has_chars())) {
                m_method.Set(method);
                m_parameters.Set(parameters);
                m_protocol.Set(protocol);
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
        m_method.SetDefault();
        m_parameters.SetDefault();
        m_protocol.SetDefault();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const request::Method& Method() const {
        return m_method;
    }
    virtual const request::Parameters& Parameters() const {
        return m_parameters;
    }
    virtual const protocol::Identifier& Protocol() const {
        return m_protocol;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    request::Method m_method;
    request::Parameters m_parameters;
    protocol::Identifier m_protocol;
};
typedef LineT<> Line;

} // namespace request
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_REQUEST_LINE_HPP 
