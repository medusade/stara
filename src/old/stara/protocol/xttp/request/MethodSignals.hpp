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
///   File: MethodSignals.hpp
///
/// Author: $author$
///   Date: 3/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_REQUEST_METHODSIGNALS_HPP
#define _STARA_PROTOCOL_XTTP_REQUEST_METHODSIGNALS_HPP

#include "stara/protocol/xttp/message/Part.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace request {

typedef ImplementBase MethodSignalsTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MethodSignalsT
///////////////////////////////////////////////////////////////////////
template
<typename TWhichOf = int, TWhichOf VNone = 0,
 class TImplements = MethodSignalsTImplements>

class _EXPORT_CLASS MethodSignalsT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhichOf WhichOf;
    enum { None = VNone };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnMethodSignal_SetWhich(const WhichOf& which) {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->MethodSignalsForwardTo())) {
            signalsForwardTo->OnMethodSignal_SetWhich(which);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual MethodSignalsT* MethodSignalsForwardTo(MethodSignalsT* to) {
        MethodSignalsT* signalsForwardTo = 0;
        return signalsForwardTo;
    }
    virtual MethodSignalsT* MethodSignalsForwardTo() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MethodSignalsT<> MethodSignals;

} // namespace request 
} // namespace xttp
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_REQUEST_METHODSIGNALS_HPP 
