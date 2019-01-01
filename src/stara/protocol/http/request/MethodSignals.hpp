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
///   File: MethodSignals.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_HTTP_REQUEST_METHODSIGNALS_HPP
#define _STARA_PROTOCOL_HTTP_REQUEST_METHODSIGNALS_HPP

#include "stara/protocol/xttp/request/MethodSignals.hpp"

namespace stara {
namespace protocol {
namespace http {
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
    virtual void OnHttpMethodSignal_GET() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_GET();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_POST() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_POST();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_PUT() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_PUT();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_DELETE() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_DELETE();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_TRACE() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_TRACE();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_CONNECT() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_CONNECT();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_OPTIONS() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_OPTIONS();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_HEAD() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_HEAD();
        }
        this->OnHttpMethodSignal_Default();
    }
    virtual void OnHttpMethodSignal_PATCH() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_PATCH();
        }
        this->OnHttpMethodSignal_Default();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnHttpMethodSignal_Default() {
        MethodSignalsT* signalsForwardTo = 0;
        if ((signalsForwardTo = this->HttpMethodSignalsForwardTo())) {
            signalsForwardTo->OnHttpMethodSignal_Default();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual MethodSignalsT* HttpMethodSignalsForwardTo(MethodSignalsT* to) {
        MethodSignalsT* signalsForwardTo = 0;
        return signalsForwardTo;
    }
    virtual MethodSignalsT* HttpMethodSignalsForwardTo() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace request 
} // namespace http 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_HTTP_REQUEST_METHODSIGNALS_HPP 
