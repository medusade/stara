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
///   File: Message.hpp
///
/// Author: $author$
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_RESPONSE_MESSAGE_HPP
#define _XOS_PROTOCOL_XTTP_RESPONSE_MESSAGE_HPP

#include "xos/protocol/xttp/response/status/Line.hpp"
#include "xos/protocol/xttp/message/Parts.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace response {

typedef message::PartsTImplements MessageTImplements;
typedef message::PartsT<status::Line> MessageTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MessageT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MessageTImplements, class TExtends = MessageTExtends>

class _EXPORT_CLASS MessageT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MessageT(const String& s)
    : Extends(s) {
    }
    MessageT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    MessageT(const char* chars)
    : Extends(chars) {
    }
    MessageT(const MessageT& copy)
    : Extends(copy) {
    }
    MessageT() {
    }
    virtual ~MessageT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MessageT<> Message;

} // namespace response
} // namespace xttp 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_RESPONSE_MESSAGE_HPP
