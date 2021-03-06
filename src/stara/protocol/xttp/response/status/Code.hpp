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
///   File: Code.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_RESPONSE_STATUS_CODE_HPP
#define _STARA_PROTOCOL_XTTP_RESPONSE_STATUS_CODE_HPP

#include "stara/protocol/xttp/message/Part.hpp"

#define STARA_PROTOCOL_XTTP_RESPONSE_STATUS_OK_CODE 200
#define STARA_PROTOCOL_XTTP_RESPONSE_STATUS_OK_REASON "OK"

namespace stara {
namespace protocol {
namespace xttp {
namespace response {
namespace status {

typedef message::PartTImplements CodeTImplements;
typedef message::Part CodeTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CodeT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CodeTImplements, class TExtends = CodeTExtends>

class _EXPORT_CLASS CodeT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CodeT(const char* chars, size_t length)
    : Extends(chars, length),
        m_value(STARA_PROTOCOL_XTTP_RESPONSE_STATUS_OK_CODE) {
        Separate();
    }
    CodeT(const char* chars)
    : Extends(chars),
        m_value(STARA_PROTOCOL_XTTP_RESPONSE_STATUS_OK_CODE) {
        Separate();
    }
    CodeT(const CodeT& copy)
    : Extends(copy), m_value(copy.Value()) {
    }
    CodeT(int value): m_value(value) {
        Combine();
    }
    CodeT(): m_value(STARA_PROTOCOL_XTTP_RESPONSE_STATUS_OK_CODE) {
        Combine();
    }
    virtual ~CodeT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = false;
        const char* chars = 0;
        this->assign_signed(m_value);
        if ((chars = this->has_chars())) {
            success = true;
        }
        return success;
    }
    virtual bool Separate() {
        bool success = false;
        const char* chars = 0;
        SetDefaults();
        if ((chars = this->has_chars())) {
            m_value = this->to_signed();
            success = true;
        }
        return success;
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
                if ((' ' != c) && ('\r' != c) && ('\n' != c)) {
                    if (('0' <= c) && ('9' >= c)) {
                        chars.append(c);
                    }
                } else {
                    if ((chars.has_chars())) {
                        this->assign(chars);
                        success = Separate();
                    }
                    break;
                }
            } else {
                count = amount;
                break;
            }
        } while (0 < amount);
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
    virtual CodeT& SetDefault() {
        SetDefaults();
        Combine();
        return *this;
    }
    virtual CodeT& SetDefaults() {
        m_value = STARA_PROTOCOL_XTTP_RESPONSE_STATUS_OK_CODE;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetValue(int value) {
        m_value = value;
        Combine();
        return m_value;
    }
    virtual int Value() const {
        return m_value;
    }
    virtual operator int() const {
        return m_value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    int m_value;
};
typedef CodeT<> Code;

} // namespace status
} // namespace response 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_RESPONSE_STATUS_CODE_HPP 
