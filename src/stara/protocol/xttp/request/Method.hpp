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
///   File: Method.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_REQUEST_METHOD_HPP
#define _STARA_PROTOCOL_XTTP_REQUEST_METHOD_HPP

#include "stara/protocol/xttp/request/MethodSignals.hpp"
#include "stara/protocol/xttp/message/Part.hpp"

#define STARA_PROTOCOL_XTTP_REQUEST_METHOD_NONE "GET"

namespace stara {
namespace protocol {
namespace xttp {
namespace request {

typedef message::PartTImplements MethodTImplements;
typedef message::Part MethodTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MethodT
///////////////////////////////////////////////////////////////////////
template
<typename TWhichOf = int, TWhichOf VNone = 0,
 class TSignalsImplements = MethodSignalsT<TWhichOf, VNone>,
 class TImplements = MethodTImplements, class TExtends = MethodTExtends>

class _EXPORT_CLASS MethodT
: virtual public TSignalsImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TSignalsImplements SignalsImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWhichOf WhichOf;
    enum { None = VNone };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MethodT(const String& s)
    : Extends(s), m_signalsForwardTo(0), m_which(None) {
    }
    MethodT(const char* chars, size_t length)
    : Extends(chars, length), m_signalsForwardTo(0), m_which(None) {
    }
    MethodT(const char* chars)
    : Extends(chars), m_signalsForwardTo(0), m_which(None) {
    }
    MethodT(const WhichOf& which)
    : m_signalsForwardTo(0), m_which(which) {
    }
    MethodT(const MethodT& copy)
    : Extends(copy), m_signalsForwardTo(0), m_which(copy.Which()) {
    }
    MethodT()
    : Extends(STARA_PROTOCOL_XTTP_REQUEST_METHOD_NONE),
      m_signalsForwardTo(0), m_which(None) {
    }
    virtual ~MethodT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        ssize_t amount = 0;
        String chars;
        SetDefault();
        do {
            if (0 < (amount = reader.Read(&c, 1))) {
                count += amount;
                if ((' ' != c)) {
                    chars.append(&c, 1);
                } else {
                    break;
                }
            } else {
                count = amount;
                return false;
            }
        } while (0 < amount);
        if ((chars.has_chars())) {
            this->assign(chars);
            this->SetWhich();
            this->OnMethodSignal_SetWhich(m_which);
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual MethodT& SetDefault() {
        this->assign(STARA_PROTOCOL_XTTP_REQUEST_METHOD_NONE);
        m_which = None;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual MethodT& SetName() {
        this->assign(NameOf(m_which));
        return *this;
    }
    virtual const MethodT& Name() const {
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WhichOf SetWhich() {
        m_which = OfName(this->chars());
        return m_which;
    }
    virtual WhichOf Which() const {
        return m_which;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WhichOf OfName(const String& name) const {
        return OfName(name.chars());
    }
    virtual WhichOf OfName(const char* name) const {
        return None;
    }
    virtual String NameOf(WhichOf which) const {
        String name(NameOfChars(which));
        return name;
    }
    virtual const char* NameOfChars(WhichOf which) const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SignalsImplements* MethodSignalsForwardTo(SignalsImplements* to) {
        SignalsImplements* signalsForwardTo = m_signalsForwardTo;
        m_signalsForwardTo = to;
        return signalsForwardTo;
    }
    virtual SignalsImplements* MethodSignalsForwardTo() const {
        return m_signalsForwardTo;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SignalsImplements* m_signalsForwardTo;
    WhichOf m_which;
};
typedef MethodT<> Method;

} // namespace request
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_REQUEST_METHOD_HPP 
