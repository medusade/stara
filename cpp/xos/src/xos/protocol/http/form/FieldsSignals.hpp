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
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_FORM_FIELDSSIGNALS_HPP
#define _XOS_PROTOCOL_HTTP_FORM_FIELDSSIGNALS_HPP

#include "xos/protocol/http/form/Field.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace form {

typedef ImplementBase FieldsSignalsImplements;
///////////////////////////////////////////////////////////////////////
///  Class: FieldsSignalsT
///////////////////////////////////////////////////////////////////////
template
<class TField = Field, class TImplements = ImplementBase>

class _EXPORT_CLASS FieldsSignalsT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnFieldsSignal_AddField(const TField& field) {
        FieldsSignalsT* to = FormFieldsSignalsForwardTo();
        if (to) {
            to->OnFieldsSignal_AddField(field);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FieldsSignalsT* ForwardFormFieldsSignalsTo(FieldsSignalsT* to) {
        return 0;
    }
    virtual FieldsSignalsT* FormFieldsSignalsForwardTo() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FieldsSignalsT<> FieldsSignals;

} // namespace form
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_FORM_FIELDSSIGNALS_HPP
