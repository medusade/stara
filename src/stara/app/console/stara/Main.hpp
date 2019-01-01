///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   Date: 1/1/2019
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_STARA_MAIN_HPP
#define _STARA_APP_CONSOLE_STARA_MAIN_HPP

#include "stara/console/getopt/Main.hpp"

namespace stara {
namespace app {
namespace console {
namespace stara {

typedef ::stara::console::getopt::MainImplements Main_implements;
typedef ::stara::console::getopt::Main Main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public Main_implements, public Main_extends {
public:
    typedef Main_implements Implements;
    typedef Main_extends Extends;
    typedef Main Derives;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_run(0) {
    }
    virtual ~Main() {
    }
private:
    Main(const Main& copy) {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = DefaultRun(argc, argv, env);
        }
        return err;
    }
    virtual int DefaultRun(int argc, char_t **argv, char_t **env) {
        int err = Usage(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    int (Derives::*m_run)(int argc, char_t **argv, char_t **env);
}; /// class _EXPORT_CLASS Main

} /// namespace stara
} /// namespace console
} /// namespace app
} /// namespace stara

#endif ///ndef _STARA_APP_CONSOLE_STARA_MAIN_HPP
