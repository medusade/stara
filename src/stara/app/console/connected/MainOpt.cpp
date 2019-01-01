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
#ifndef _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP
#include "stara/app/console/connected/MainOpt.hpp"
#include "stara/app/console/Main.hpp"

namespace stara {
namespace app {
namespace console {
namespace connected {

typedef stara::app::console::MainImplements MainImplements;
typedef stara::app::console::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTransportOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
#else // _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual int OnClientOption
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = SetClient();
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int OnServerOption
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = SetServer();
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int OnHostOption
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = 0;
    if ((optarg) && (optarg[0])) {
        String host(optarg);
        err = SetHost(host);
    }
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int OnPortOption
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = 0;
    if ((optarg) && (optarg[0])) {
        String port(optarg);
        unsigned number = 0;
        if (0 < (number = port.to_unsigned())) {
            err = SetPort(port, number);
        }
    }
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int OnFamilyOption
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = 0;
    if ((optarg) && (optarg[0])) {
        String name(optarg);
        if ((!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG_LOCAL_C)
             || (!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG_LOCAL)))) {
            err = SetLocal();
        } else {
            if ((!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG_IPV4_C)
                 || (!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG_IPV4)))) {
                err = SetIpv4();
            } else {
                if ((!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG_IPV6_C)
                     || (!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG_IPV6)))) {
                    err = SetIpv6();
                } else {
                    err = OnInvalidOptionArg
                    (optval, optarg, optname, optind, argc, argv, env);
                }
            }
        }
    }
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int OnTransportOption
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = 0;
    if ((optarg) && (optarg[0])) {
        String name(optarg);
        if ((!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTARG_STREAM_C)
             || (!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTARG_STREAM)))) {
            err = SetStream();
        } else {
            if ((!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTARG_DGRAM_C)
                 || (!name.compare(STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTARG_DGRAM)))) {
                err = SetDgram();
            } else {
                err = OnInvalidOptionArg
                (optval, optarg, optname, optind, argc, argv, env);
            }
        }
    }
    return err;
}
#endif // _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case STARA_APP_CONSOLE_CONNECTED_MAIN_CLIENT_OPTVAL_C:
            err = OnClientOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_SERVER_OPTVAL_C:
            err = OnServerOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_PORT_OPTVAL_C:
            err = OnPortOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTVAL_C:
            err = OnFamilyOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTVAL_C:
            err = OnTransportOption
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
        case STARA_APP_CONSOLE_CONNECTED_MAIN_CLIENT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_CONNECTED_MAIN_CLIENT_OPTARG;
            chars = STARA_APP_CONSOLE_CONNECTED_MAIN_CLIENT_OPTUSE;
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_SERVER_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_CONNECTED_MAIN_SERVER_OPTARG;
            chars = STARA_APP_CONSOLE_CONNECTED_MAIN_SERVER_OPTUSE;
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_HOST_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_CONNECTED_MAIN_HOST_OPTARG;
            chars = STARA_APP_CONSOLE_CONNECTED_MAIN_HOST_OPTUSE;
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_PORT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_CONNECTED_MAIN_PORT_OPTARG;
            chars = STARA_APP_CONSOLE_CONNECTED_MAIN_PORT_OPTUSE;
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTARG;
            chars = STARA_APP_CONSOLE_CONNECTED_MAIN_FAMILY_OPTUSE;
            break;
        case STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTVAL_C:
            optarg = STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTARG;
            chars = STARA_APP_CONSOLE_CONNECTED_MAIN_TRANSPORT_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = STARA_APP_CONSOLE_CONNECTED_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            STARA_APP_CONSOLE_CONNECTED_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = STARA_APP_CONSOLE_CONNECTED_MAIN_ARGS;
        static const char_t* _argv[] = {
            STARA_APP_CONSOLE_CONNECTED_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

#ifndef _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP
};

} // namespace connected
} // namespace console 
} // namespace app 
} // namespace stara 
#endif // _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP
