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
///   File: MainOpt.cpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_HELLO_MAIN_HPP
#include "stara/app/console/hello/MainOpt.hpp"

namespace stara {
namespace app {
namespace console {
namespace hello {

typedef stara::console::getopt::MainImplements MainImplements;
typedef stara::console::getopt::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;
#endif // _STARA_APP_CONSOLE_HELLO_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case STARA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C:
            err = OnClientOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C:
            err = OnServerOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C:
            err = OnPortOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C:
            err = OnFamilyOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case STARA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTARG;
            chars = STARA_APP_CONSOLE_HELLO_MAIN_CLIENT_OPTUSE;
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTARG;
            chars = STARA_APP_CONSOLE_HELLO_MAIN_SERVER_OPTUSE;
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_HOST_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_HELLO_MAIN_HOST_OPTARG;
            chars = STARA_APP_CONSOLE_HELLO_MAIN_HOST_OPTUSE;
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_PORT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_HELLO_MAIN_PORT_OPTARG;
            chars = STARA_APP_CONSOLE_HELLO_MAIN_PORT_OPTUSE;
            break;
        case STARA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG;
            chars = STARA_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = STARA_APP_CONSOLE_HELLO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            STARA_APP_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = STARA_APP_CONSOLE_HELLO_MAIN_ARGS;
        static const char_t* _argv[] = {
            STARA_APP_CONSOLE_HELLO_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

#ifndef _STARA_APP_CONSOLE_HELLO_MAIN_HPP
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace stara 
#endif // _STARA_APP_CONSOLE_HELLO_MAIN_HPP
