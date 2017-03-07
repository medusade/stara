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
#include "stara/protocol/http/request/Method.hpp"
#include "stara/protocol/http/url/encoded/Reader.hpp"

namespace stara {
namespace app {
namespace console {
namespace connected {
namespace http {

typedef stara::app::console::connected::MainImplements MainImplements;
typedef stara::app::console::connected::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main() {
    }
    virtual ~Main() {
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
            CRONO_LOG_DEBUG("OnReadRequestGET(action, stream)...");
            success = OnReadRequestGET(action, stream);
            break;

        case stara::protocol::http::request::Method::POST:
            CRONO_LOG_DEBUG("OnReadRequestPOST(action, stream)...");
            success = OnReadRequestPOST(action, stream);
            break;

        default:
            CRONO_LOG_ERROR("...unsupported method \"" << xmethod << "\"");
            break;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnReadRequestGET
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }
    virtual bool OnReadRequestPOST
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }

#include "stara/app/console/connected/http/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    stara::protocol::xttp::request::Message m_request;
    stara::protocol::xttp::response::Message m_response;
};

} // namespace http 
} // namespace connected 
} // namespace console 
} // namespace app 
} // namespace stara 

#endif // _STARA_APP_CONSOLE_CONNECTED_HTTP_MAIN_HPP 
