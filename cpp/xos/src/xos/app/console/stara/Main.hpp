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
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_STARA_MAIN_HPP
#define _XOS_APP_CONSOLE_STARA_MAIN_HPP

#include "xos/app/console/stara/MainOpt.hpp"
#include "xos/app/console/rete/Main.hpp"
#include "xos/protocol/xttp/response/status/Line.hpp"
#include "xos/protocol/xttp/request/Message.hpp"
#include "xos/protocol/xttp/request/Line.hpp"
#include "xos/protocol/xttp/message/header/Fields.hpp"
#include "xos/protocol/xttp/message/Line.hpp"

namespace xos {
namespace app {
namespace console {
namespace stara {

typedef rete::MainImplements MainImplements;
typedef rete::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = MainOpt,
 class TImplements = MainImplements, class TExtends = MainExtends>

class _EXPORT_CLASS MainT
: virtual public TOptImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainT Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadXttpRequest
    (io::CharReader& in, String& rs) {
        ssize_t count = 0, amount = 0;
        char c = 0;
        //count = this->ReadXttp(in, rs);
        /*if ((m_requestLine.Read(amount, c, in))) {
            count += amount;
            XOS_LOG_DEBUG("...read line method = \"" << m_requestLine.Method() << "\" parameters = \"" << m_requestLine.Parameters() << "\" protocol = \"" << m_requestLine.Protocol() << "\"");
            if (0 < (amount = ReadXttpHeaders(in, rs, c))) {
                count += amount;
            }
        }*/
        if ((m_requestMessage.Read(amount, c, in))) {
            const protocol::xttp::request::Line& line = m_requestMessage.Line();
            const protocol::xttp::request::Method& method = line.Method();
            const protocol::xttp::request::Parameters& parameters = line.Parameters();
            const protocol::xttp::protocol::Identifier& protocol = line.Protocol();
            count += amount;
            XOS_LOG_DEBUG("...read method = \"" << method << "\" parameters = \"" << parameters << "\" protocol = \"" << protocol << "\"");
        }
        return count;
    }
    virtual ssize_t ReadXttpRequestLine
    (io::CharReader& in, String& rs) {
        ssize_t count = 0, amount = 0;
        char c = 0;
        if ((m_requestLine.Read(amount, c, in))) {
            const protocol::xttp::request::Line& line = m_requestLine;
            const protocol::xttp::request::Method& method = line.Method();
            const protocol::xttp::request::Parameters& parameters = line.Parameters();
            const protocol::xttp::protocol::Identifier& protocol = line.Protocol();
            count += amount;
            XOS_LOG_DEBUG("...read method = \"" << method << "\" parameters = \"" << parameters << "\" protocol = \"" << protocol << "\"");
            if (0 < (amount = ReadXttpHeaders(in, rs, c))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t ReadXttpResponse
    (io::CharReader& in, String& rs) {
        ssize_t count = 0, amount = 0;
        char c = 0;
        //count = this->ReadXttp(in, rs);
        count = this->ReadXttpResponseLine(in, rs);
        return count;
    }
    virtual ssize_t ReadXttpResponseLine
    (io::CharReader& in, String& rs) {
        ssize_t count = 0, amount = 0;
        char c = 0;
        if ((m_responseLine.Read(amount, c, in))) {
            const protocol::xttp::response::status::Line& line = m_responseLine;
            const protocol::xttp::protocol::Identifier& protocol = m_responseLine.Protocol();
            const protocol::xttp::response::status::Code& code = m_responseLine.Code();
            const protocol::xttp::response::status::Reason& reason = m_responseLine.Reason();
            XOS_LOG_DEBUG("...read protocol = \"" << protocol << "\" code = \"" << code << "\" reason = \"" << reason << "\" ");
            count += amount;
            if (0 < (amount = ReadXttpHeaders(in, rs, c))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t ReadXttp
    (io::CharReader& in, String& rs) {
        ssize_t count = 0, amount = 0;
        char c = 0;

        if ((m_line.Read(amount, c, in))) {
            count += amount;
            XOS_LOG_DEBUG("...read line = \"" << m_line << "\"");
            if (0 < (amount = ReadXttpHeaders(in, rs, c))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t ReadXttpHeaders
    (io::CharReader& in, String& rs, char& c) {
        ssize_t count = 0, amount = 0;
        if ((m_headers.Read(amount, c, in))) {
            count += amount;
        }
        return count;
    }
    virtual ssize_t ReadXttpHeaderLines
    (io::CharReader& in, String& rs, char& c) {
        ssize_t count = 0, amount = 0;
        do {
            if ((m_line.Read(amount, c, in))) {
                count += amount;
                XOS_LOG_DEBUG("...read line = \"" << m_line << "\"");
            } else {
                break;
            }
        } while (0 < (m_line.Length()));
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    protocol::xttp::response::status::Line m_responseLine;
    protocol::xttp::request::Message m_requestMessage;
    protocol::xttp::request::Line m_requestLine;
    protocol::xttp::message::Line m_line;
    protocol::xttp::message::header::Fields m_headers;
};
typedef  MainT<> Main;

} // namespace stara
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_STARA_MAIN_HPP 
