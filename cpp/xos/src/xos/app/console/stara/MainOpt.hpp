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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_STARA_MAINOPT_HPP
#define _XOS_APP_CONSOLE_STARA_MAINOPT_HPP

#include "xos/app/console/rete/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_STARA_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_RETE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_STARA_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_RETE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_STARA_MAIN_ARGS 0
#define XOS_APP_CONSOLE_STARA_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace app {
namespace console {
namespace stara {

typedef rete::MainOpt MainOptTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptTImplements>
class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace stara
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_STARA_MAINOPT_HPP 

        

