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
///   File: Message.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_REQUEST_MESSAGE_HPP
#define _STARA_PROTOCOL_XTTP_REQUEST_MESSAGE_HPP

#include "stara/protocol/xttp/request/Line.hpp"
#include "stara/protocol/xttp/message/Parts.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace request {

typedef message::PartsTImplements MessageTImplements;
typedef message::PartsT<request::Line> MessageTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MessageT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MessageTImplements,
 class TExtends = MessageTExtends>

class _EXPORT_CLASS MessageT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
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

} // namespace request
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_REQUEST_MESSAGE_HPP 
