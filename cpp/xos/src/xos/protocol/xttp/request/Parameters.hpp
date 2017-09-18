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
///   File: Parameters.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_REQUEST_PARAMETERS_HPP
#define _XOS_PROTOCOL_XTTP_REQUEST_PARAMETERS_HPP

#include "xos/protocol/xttp/message/Part.hpp"

#define XOS_PROTOCOL_XTTP_REQUEST_PARAMETERS_DEFAULT "/"

namespace xos {
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
    : Extends(XOS_PROTOCOL_XTTP_REQUEST_PARAMETERS_DEFAULT) {
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
                    chars.Append(&c, 1);
                } else {
                    break;
                }
            } else {
                count = amount;
                return false;
            }
        } while (0 < amount);
        if ((chars.HasChars())) {
            this->Assign(chars);
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ParametersT& SetDefault() {
        this->Assign(XOS_PROTOCOL_XTTP_REQUEST_PARAMETERS_DEFAULT);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ParametersT<> Parameters;

} // namespace request 
} // namespace xttp 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_REQUEST_PARAMETERS_HPP 
