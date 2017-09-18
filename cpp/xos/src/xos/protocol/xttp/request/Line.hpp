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
///   File: Line.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_REQUEST_LINE_HPP
#define _XOS_PROTOCOL_XTTP_REQUEST_LINE_HPP

#include "xos/protocol/xttp/protocol/Identifier.hpp"
#include "xos/protocol/xttp/request/Method.hpp"
#include "xos/protocol/xttp/request/Parameters.hpp"
#include "xos/protocol/xttp/message/Line.hpp"
#include "xos/protocol/xttp/message/Part.hpp"

namespace xos {
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
        if ((method = m_method.HasChars())
            && (parameters = m_parameters.HasChars())
            && (protocol = m_protocol.HasChars())) {
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

        if ((chars = this->HasChars(length))) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, method, parameters, protocol;

            for (part = &method; chars != end; ++chars) {
                if (' ' != (c = *chars)) {
                    part->Append(&c, 1);
                } else {
                    if (part == &method) {
                        if (method.HasChars()) {
                            // ?' '
                            part = &parameters;
                        } else {
                            // ' '
                            return false;
                        }
                    } else {
                        if (part != &protocol) {
                            if (parameters.HasChars()) {
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
            if ((method.HasChars())
                && (parameters.HasChars())
                && (protocol.HasChars())) {
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
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_REQUEST_LINE_HPP 
