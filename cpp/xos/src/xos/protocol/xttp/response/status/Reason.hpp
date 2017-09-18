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
///   File: Reason.hpp
///
/// Author: $author$
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_RESPONSE_STATUS_REASON_HPP
#define _XOS_PROTOCOL_XTTP_RESPONSE_STATUS_REASON_HPP

#include "xos/protocol/xttp/response/status/Code.hpp"
#include "xos/protocol/xttp/message/Part.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace response {
namespace status {

typedef message::PartTImplements ReasonTImplements;
typedef message::Part ReasonTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ReasonT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ReasonTImplements, class TExtends = ReasonTExtends>

class _EXPORT_CLASS ReasonT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ReasonT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    ReasonT(const char* chars)
    : Extends(chars) {
    }
    ReasonT(const ReasonT& copy)
    : Extends(copy) {
    }
    ReasonT()
    : Extends(XOS_PROTOCOL_XTTP_RESPONSE_STATUS_DEFAULT_REASON) {
    }
    virtual ~ReasonT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        ssize_t amount = 0;
        this->SetDefault();
        do {
            if (0 < (amount = reader.Read(&c, 1))) {
                count += amount;
                if (('\r' != c) && ('\n' != c)) {
                    this->Append(&c, 1);
                } else {
                    success = true;
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
    virtual ReasonT& SetDefault() {
        this->assign(XOS_PROTOCOL_XTTP_RESPONSE_STATUS_DEFAULT_REASON);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ReasonT<> Reason;

} // namespace status
} // namespace response 
} // namespace xttp 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_RESPONSE_STATUS_REASON_HPP 
