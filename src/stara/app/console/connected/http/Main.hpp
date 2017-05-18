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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 3/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_CONNECTED_HTTP_MAIN_HPP
#define _STARA_APP_CONSOLE_CONNECTED_HTTP_MAIN_HPP

#include "stara/app/console/connected/http/MainOpt.hpp"
#include "stara/app/console/connected/Main.hpp"
#include "stara/protocol/xttp/response/Message.hpp"
#include "stara/protocol/xttp/request/Message.hpp"
#include "stara/protocol/xttp/message/body/Reader.hpp"
#include "stara/protocol/http/request/Method.hpp"
#include "stara/protocol/http/url/encoded/Reader.hpp"
#include "stara/protocol/http/url/encoded/form/ContentType.hpp"
#include "stara/protocol/http/url/encoded/form/Fields.hpp"
#include "stara/protocol/http/form/Fields.hpp"
#include "stara/protocol/http/form/FieldsSignals.hpp"

namespace stara {
namespace app {
namespace console {
namespace connected {
namespace http {

typedef stara::protocol::http::form::FieldsSignals MainSignalsImplements;
typedef stara::app::console::connected::MainImplements MainImplements;
typedef stara::app::console::connected::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main
: virtual public MainSignalsImplements,
  virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main() {
        m_urlEncodedFormFields.ForwardFormFieldsSignalsTo(this);
    }
    virtual ~Main() {
        m_urlEncodedFormFields.ForwardFormFieldsSignalsTo(0);
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool RreadRequest
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = false;
        ssize_t count = 0;
        char c = 0;
        if ((m_request.Read(count, c, stream))) {
            if ((OnReadRequest(action, stream))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool WriteResponse
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = false;
        ssize_t count = 0;
        if ((m_response.Write(count, stream))) {
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnReadRequest
    (RunAction& action, stara::io::CharStream& stream) {
        const stara::protocol::xttp::request::Method& xmethod = m_request.Line().Method();
        stara::protocol::http::request::Method method(xmethod);
        bool success = false;

        switch(method.Which()) {
        case stara::protocol::http::request::Method::GET:
            CRONO_LOG_DEBUG("OnReadGET(action, stream)...");
            success = OnReadGET(action, stream);
            break;

        case stara::protocol::http::request::Method::POST:
            CRONO_LOG_DEBUG("OnReadPOST(action, stream)...");
            success = OnReadPOST(action, stream);
            break;

        default:
            CRONO_LOG_ERROR("...unsupported method \"" << xmethod << "\"");
            break;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnReadGET
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }
    virtual bool OnReadPOST
    (RunAction& action, stara::io::CharStream& stream) {
        const stara::protocol::xttp::message::Part& contentType
              = m_request.Headers().ContentType();
        bool success = true;

        if (!(m_urlEncodedFormContentType.Compare(contentType))) {
            CRONO_LOG_DEBUG("OnPOSTUrlEncodedForm(action, stream)...");
            success = OnPOSTUrlEncodedForm(action, stream);
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnPOSTUrlEncodedForm
    (RunAction& action, stara::io::CharStream& stream) {
        size_t contentLength = m_request.ContentLength();
        bool success = true;

        if (0 < (contentLength)) {
            stara::protocol::xttp::message::body::CharReader reader(stream, contentLength);
            ssize_t count = 0;
            char c = 0;

            success = m_urlEncodedFormFields.Read(count, c, reader);
        }
        return success;
    }

    virtual stara::protocol::xttp::message::header::Field*
    AddResponseHeaderField(const String& name, const String& value) {
        stara::protocol::xttp::message::header::Field* f = 0;
        if ((f = m_response.AddHeaderField(name, value))) {
            return f;
        }
        return 0;
    }

#include "stara/app/console/connected/http/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    stara::protocol::xttp::request::Message m_request;
    stara::protocol::xttp::response::Message m_response;
    stara::protocol::http::url::encoded::form::ContentType m_urlEncodedFormContentType;
    stara::protocol::http::url::encoded::form::Fields m_urlEncodedFormFields;
};

} // namespace http 
} // namespace connected 
} // namespace console 
} // namespace app 
} // namespace stara 

#endif // _STARA_APP_CONSOLE_CONNECTED_HTTP_MAIN_HPP 
