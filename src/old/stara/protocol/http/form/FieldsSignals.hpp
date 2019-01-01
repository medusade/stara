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
///   Date: 3/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_HTTP_FORM_FIELDSSIGNALS_HPP
#define _STARA_PROTOCOL_HTTP_FORM_FIELDSSIGNALS_HPP

#include "stara/protocol/http/form/Field.hpp"

namespace stara {
namespace protocol {
namespace http {
namespace form {

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
        FieldsSignals* to = FormFieldsSignalsForwardTo();
        if (to) {
            to->OnFieldsSignal_AddField(field);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FieldsSignals* ForwardFormFieldsSignalsTo(FieldsSignals* to) {
        return 0;
    }
    virtual FieldsSignals* FormFieldsSignalsForwardTo() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace form
} // namespace http 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_HTTP_FORM_FIELDSSIGNALS_HPP 
