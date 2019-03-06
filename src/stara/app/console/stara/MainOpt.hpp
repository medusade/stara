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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 3/2/2019
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_STARA_MAINOPT_HPP
#define _STARA_APP_CONSOLE_STARA_MAINOPT_HPP

#include "stara/console/lib/stara/version/Main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPT "client"
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTARG_RESULT 0
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTARG ""
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTUSE "Run as client"
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTVAL_S "c"
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTVAL_C 'c'
#define STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTION \
   {STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPT, \
    STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTARG_REQUIRED, \
    STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTARG_RESULT, \
    STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTVAL_C}, \

#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPT "server"
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTARG_RESULT 0
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTARG ""
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTUSE "Run as server"
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTVAL_S "s"
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTVAL_C 's'
#define STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTION \
   {STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPT, \
    STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTARG_REQUIRED, \
    STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTARG_RESULT, \
    STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTVAL_C}, \

#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPT "host"
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTARG_RESULT 0
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTARG "string"
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTUSE "Host name or address"
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTVAL_S "o:"
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTVAL_C 'o'
#define STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTION \
   {STARA_APP_CONSOLE_STARA_MAIN_HOST_OPT, \
    STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTARG_REQUIRED, \
    STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTARG_RESULT, \
    STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTVAL_C}, \

#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPT "port"
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTARG_RESULT 0
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTARG "number"
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTUSE "Port number"
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTVAL_S "p:"
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTVAL_C 'p'
#define STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTION \
   {STARA_APP_CONSOLE_STARA_MAIN_PORT_OPT, \
    STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTARG_REQUIRED, \
    STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTARG_RESULT, \
    STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTVAL_C}, \

#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPT "family"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_RESULT 0
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_LOCAL "l"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_IPV4 "4"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_IPV6 "6"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_LOCAL "local"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_IPV4 "ipv4"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_IPV6 "ipv6"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG "{ "\
    "(" STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_LOCAL ")" \
    STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_LOCAL " | " \
    "(" STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_IPV4 ")" \
    STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_IPV4 " | " \
    "(" STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_IPV6 ")" \
    STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_IPV6 " }"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTUSE "Address family"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTVAL_S "f:"
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTVAL_C 'f'
#define STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTION \
   {STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPT, \
    STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_REQUIRED, \
    STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_RESULT, \
    STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define STARA_APP_CONSOLE_STARA_MAIN_OPTIONS_CHARS \
   STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTVAL_S \
   STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTVAL_S \
   STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTVAL_S \
   STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTVAL_S \
   STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTVAL_S \
   STARA_CONSOLE_GETOPT_MAIN_OPTIONS_CHARS

#define STARA_APP_CONSOLE_STARA_MAIN_OPTIONS_OPTIONS \
   STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTION \
   STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTION \
   STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTION \
   STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTION \
   STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTION \
   STARA_CONSOLE_GETOPT_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define STARA_APP_CONSOLE_STARA_MAIN_ARGS 0
#define STARA_APP_CONSOLE_STARA_MAIN_ARGV

namespace stara {
namespace app {
namespace console {
namespace stara {

typedef ::stara::console::lib::stara::version::Main::Implements MainOptImplements;
typedef ::stara::console::lib::stara::version::Main MainOptExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainOpt
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainOpt: virtual public MainOptImplements, public MainOptExtends {
public:
    typedef MainOptImplements Implements;
    typedef MainOptExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainOpt() {
    }
    virtual ~MainOpt() {
    }
private:
    MainOpt(const MainOpt& copy) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTVAL_C:
            err = OnClientOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTVAL_C:
            err = OnServerOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTVAL_C:
            err = OnPortOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTVAL_C:
            err = OnFamilyOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTARG;
            chars = STARA_APP_CONSOLE_STARA_MAIN_CLIENT_OPTUSE;
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTARG;
            chars = STARA_APP_CONSOLE_STARA_MAIN_SERVER_OPTUSE;
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTARG;
            chars = STARA_APP_CONSOLE_STARA_MAIN_HOST_OPTUSE;
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTARG;
            chars = STARA_APP_CONSOLE_STARA_MAIN_PORT_OPTUSE;
            break;
        case STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG;
            chars = STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = STARA_APP_CONSOLE_STARA_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            STARA_APP_CONSOLE_STARA_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = STARA_APP_CONSOLE_STARA_MAIN_ARGS;
        static const char_t* _argv[] = {
            STARA_APP_CONSOLE_STARA_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS MainOpt

} /// namespace stara
} /// namespace console
} /// namespace app
} /// namespace stara

#endif /// _STARA_APP_CONSOLE_STARA_MAINOPT_HPP 
