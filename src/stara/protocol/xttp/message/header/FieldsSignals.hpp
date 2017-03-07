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
///   File: FieldsSignals.hpp
///
/// Author: $author$
///   Date: 3/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELDSSIGNALS_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELDSSIGNALS_HPP

#include "stara/protocol/xttp/message/header/Field.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace message {
namespace header {

typedef ImplementBase FieldsSignalsImplements;
///////////////////////////////////////////////////////////////////////
///  Class: FieldsSignals
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS FieldsSignals: virtual public FieldsSignalsImplements {
public:
    typedef FieldsSignalsImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnFieldsSignal_AddField(const Field& field) {
        FieldsSignals* to = FieldsSignalsForwardTo();
        if (to) {
            to->OnFieldsSignal_AddField(field);
        }
    }
    virtual void OnFieldsSignal_AddFieldContentLength
    (const Field& field, const Part& value, size_t length) {
        FieldsSignals* to = FieldsSignalsForwardTo();
        if (to) {
            to->OnFieldsSignal_AddFieldContentLength(field, value, length);
        }
    }
    virtual void OnFieldsSignal_AddFieldContentType
    (const Field& field, const Part& value) {
        FieldsSignals* to = FieldsSignalsForwardTo();
        if (to) {
            to->OnFieldsSignal_AddFieldContentType(field, value);
        }
    }
    virtual void OnFieldsSignal_AddFieldContentEncoding
    (const Field& field, const Part& value) {
        FieldsSignals* to = FieldsSignalsForwardTo();
        if (to) {
            to->OnFieldsSignal_AddFieldContentEncoding(field, value);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FieldsSignals* ForwardFieldsSignalsTo(FieldsSignals* to) {
        return 0;
    }
    virtual FieldsSignals* FieldsSignalsForwardTo() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace header 
} // namespace message 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_HEADER_FIELDSSIGNALS_HPP
