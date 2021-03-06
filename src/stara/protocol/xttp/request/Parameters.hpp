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
///   File: Parameters.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_REQUEST_PARAMETERS_HPP
#define _STARA_PROTOCOL_XTTP_REQUEST_PARAMETERS_HPP

#include "stara/protocol/xttp/message/Part.hpp"

#define STARA_PROTOCOL_XTTP_REQUEST_PARAMETERS_ROOT "/"

namespace stara {
namespace protocol {
namespace xttp {
namespace request {

typedef message::PartTImplements ParametersTImplements;
typedef message::Part ParametersTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ParametersT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ParametersTImplements,
 class TExtends = ParametersTExtends>

class _EXPORT_CLASS ParametersT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ParametersT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    ParametersT(const char* chars)
    : Extends(chars) {
    }
    ParametersT(const ParametersT& copy)
    : Extends(copy) {
    }
    ParametersT()
    : Extends(STARA_PROTOCOL_XTTP_REQUEST_PARAMETERS_ROOT) {
    }
    virtual ~ParametersT() {
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
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ParametersT& SetDefault() {
        this->assign(STARA_PROTOCOL_XTTP_REQUEST_PARAMETERS_ROOT);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ParametersT<> Parameters;

} // namespace request
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_REQUEST_PARAMETERS_HPP 
