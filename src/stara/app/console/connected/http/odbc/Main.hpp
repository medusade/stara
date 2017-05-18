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
#ifndef _STARA_APP_CONSOLE_CONNECTED_HTTP_ODBC_MAIN_HPP
#define _STARA_APP_CONSOLE_CONNECTED_HTTP_ODBC_MAIN_HPP

#include "etiris/db/ODBC.hpp"
#include "crono/io/Logger.hpp"
#define ETERIS_LOG_ERROR CRONO_LOG_ERROR
#include "etiris/db/odbc/cgi/Main.hpp"
#include "stara/app/console/connected/http/odbc/Main.hpp"
#include "stara/app/console/connected/http/Main.hpp"
#include "nadir/console/io.hpp"

namespace stara {
namespace app {
namespace console {
namespace connected {
namespace http {
namespace odbc {

typedef nadir::console::iot
<char, char, 0, io::CharStream*, int, 0> MainExtendIoImplements;
typedef stara::app::console::connected::http::MainImplements MainExtendExtendImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainExtendImplements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainExtendImplements
: virtual public MainExtendIoImplements,
  virtual public MainExtendExtendImplements {
public:
    typedef MainExtendIoImplements IoImplements;
    typedef MainExtendExtendImplements Implements;
};
typedef stara::app::console::connected::http::Main MainExtendExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainExtend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainExtend
: virtual public MainExtendImplements, public MainExtendExtends {
public:
    typedef MainExtendImplements Implements;
    typedef MainExtendExtends Extends;

    typedef typename IoImplements::string_t string_t;
    typedef typename IoImplements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainExtend(): m_out(0) {
    }
    virtual ~MainExtend() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* set_content_type(const string_t& to) {
        return set_content_type(to.chars());
    }
    virtual const char_t* set_content_type(const char_t* chars) {
        if ((chars) && (chars[0])) {
        }
        return chars;
    }
    virtual const char_t* content_type() const {
        const char_t* chars = 0;
        return chars;
    }
    virtual const char_t* content_type_text() const {
        const char_t* chars = "text/plain";
        return chars;
    }
    virtual const char_t* content_type_xml() const {
        const char_t* chars = "text/xml";
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t errfv(const char_t* format, va_list va) {
        ssize_t count = this->ErrFV(format, va);
        return count;
    }
    virtual ssize_t errlv(const char_t* out, va_list va) {
        ssize_t count = this->ErrLV(out, va);
        return count;
    }
    virtual ssize_t errln(const char_t* out, ssize_t length = -1) {
        ssize_t count = (0 > length)?(this->ErrLn(out)):(this->ErrLn(out, length));
        return count;
    }
    virtual ssize_t errln() {
        ssize_t count = this->ErrLn();
        return count;
    }
    virtual ssize_t err(const char_t* out, ssize_t length = -1) {
        ssize_t count = (0 < length)?(this->Err(out)):(this->Err(out, length));
        return count;
    }
    virtual ssize_t err_flush() {
        ssize_t count = this->ErrFlush();
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::out;
    virtual ssize_t out(file_t f, const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        if ((out) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (length)) {
                if (0 < (amount = f->Write(out, sizeof(char_t)*length))) {
                    count += amount;
                }
            } else {
                if (0 > (length)) {
                    for (; *out; ++out) {
                        if (0 < (amount = f->Write(out, sizeof(char_t)))) {
                            count += amount;
                            continue;
                        }
                        break;
                    }
                }
            }
        }
        return count;
    }
    virtual file_t std_out() const {
        return ((file_t)m_out);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    stara::io::CharStream* m_out;
};

typedef MainExtendImplements MainImplements;
typedef etiris::db::odbc::cgi::MainT<MainImplements, MainExtend> MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;

    typedef stara::protocol::http::form::Field Field;
    typedef stara::protocol::xttp::message::Part Part;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main() {
    }
    virtual ~Main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool AfterRreadRequest
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        //this->AddResponseHeaderField("Content-Type", "text/plain");
        //this->AddResponseHeaderField("Content-Length", "7");
        return success;
    }
    virtual bool AfterWriteResponse
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        this->m_out = &stream;
        this->RunQuery();
        //this->out("Hello\r\n");
        this->m_out = 0;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnFieldsSignal_AddField(const Field& field) {
        if (!(SetParamFromField(field, param_source_names(), param_source_))) {

            if (!(SetParamFromField(field, param_table_names(), param_table_))) {

                if (!(SetParamFromField(field, param_select_names(), param_select_))) {

                    if (!(SetParamFromField(field, param_where_names(), param_where_))) {

                        if (!(SetParamFromField(field, param_query_names(), param_query_))) {
                        }
                    }
                }
            }
        }
    }
    virtual bool SetParamFromField
    (const Field& field, const char_t** names, string_t& param) {
        const Part& value = field.Value();

        if ((names) && (value.has_chars())) {
            const Part& name = field.Name();
            const char_t* chars = 0;

            for (chars = (*names); chars; chars = *(++names)) {
                if (!(name.Compare(chars))) {
                    CRONO_LOG_DEBUG("...parameter \"" << name << "\" = \"" << value << "\"");
                    param.assign(value);
                    return true;
                }
            }
        }
        return false;
    }

#include "stara/app/console/connected/http/odbc/Main.hpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace odbc 
} // namespace http 
} // namespace connected 
} // namespace console 
} // namespace app 
} // namespace stara 

#endif // _STARA_APP_CONSOLE_CONNECTED_HTTP_ODBC_MAIN_HPP 
