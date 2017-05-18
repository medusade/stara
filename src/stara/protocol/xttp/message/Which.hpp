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
///   File: Which.hpp
///
/// Author: $author$
///   Date: 3/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_WHICH_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_WHICH_HPP

#include "stara/protocol/xttp/message/Part.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace message {

typedef ImplementBase WhichTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: WhichT
///////////////////////////////////////////////////////////////////////
template
<typename TWhichOf = int, typename TNoneOf = TWhichOf, TNoneOf VNoneOf = 0,
 class TImplements = WhichTImplements>

class _EXPORT_CLASS WhichT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhichOf WhichOf;
    enum { NoneOf = VNoneOf };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WhichOf OfName(const String& name) const {
        return OfName(name.has_chars());
    }
    virtual WhichOf OfName(const char* name) const {
        return NoneOf;
    }
    virtual String NameOf(WhichOf of) const {
        String name(NameOfChars(of));
        return name;
    }
    virtual const char* NameOfChars(WhichOf of) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WhichT<> Which;

} // namespace message 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_WHICH_HPP 
