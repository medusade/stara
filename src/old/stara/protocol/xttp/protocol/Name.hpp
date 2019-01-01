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
///   File: Name.hpp
///
/// Author: $author$
///   Date: 12/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_PROTOCOL_NAME_HPP
#define _STARA_PROTOCOL_XTTP_PROTOCOL_NAME_HPP

#include "stara/protocol/xttp/message/Part.hpp"

#define STARA_PROTOCOL_XTTP_PROTOCOL_NAME_HTTP "HTTP"

namespace stara {
namespace protocol {
namespace xttp {
namespace protocol {

typedef message::PartTImplements NameTImplements;
typedef message::Part NameTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: NameT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = NameTImplements,
 class TExtends = NameTExtends>

class _EXPORT_CLASS NameT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    NameT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    NameT(const char* chars)
    : Extends(chars) {
    }
    NameT(const NameT& copy)
    : Extends(copy) {
    }
    NameT()
    : Extends(STARA_PROTOCOL_XTTP_PROTOCOL_NAME_HTTP) {
    }
    virtual ~NameT() {
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
                if (('/' != c)) {
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
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual NameT& SetDefault() {
        this->assign(STARA_PROTOCOL_XTTP_PROTOCOL_NAME_HTTP);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef NameT<> Name;

} // namespace protocol
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_PROTOCOL_NAME_HPP 
