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
///   File: Processor.hpp
///
/// Author: $author$
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_PROCESSOR_HPP
#define _XOS_PROTOCOL_XTTP_PROCESSOR_HPP

#include "xos/protocol/xttp/response/Message.hpp"
#include "xos/protocol/xttp/request/Message.hpp"
#include "xos/protocol/xttp/message/Part.hpp"
#include "xos/base/Signal.hpp"

namespace xos {
namespace protocol {
namespace xttp {

typedef ImplementBase ProcessorTImplements;
typedef Base ProcessorTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ProcessorT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ProcessorTImplements, class TExtends = ProcessorTExtends>

class _EXPORT_CLASS ProcessorT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef int ProcessingStatus;
    enum {
        ProcessingNone,
        ProcessingDone,
        ProcessingFailed,
        ProcessingContinued
    };

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: ProcessorT
    ///////////////////////////////////////////////////////////////////////
    ProcessorT() {
    }
    virtual ~ProcessorT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ProcessingStatus operator()
    (Signal& restart, Signal& stop, 
     response::Message& rs, const request::Message& rq) {
        return ProcessingNone;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ProcessorT<> Processor;

} // namespace xttp 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_PROCESSOR_HPP 

        

