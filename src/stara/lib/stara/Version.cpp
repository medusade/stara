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
///   File: Version.cpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#include "stara/lib/stara/Version.hpp"

#if !defined(STARA_LIB_STARA_VERSION_NAME)
#define STARA_LIB_STARA_VERSION_NAME "libstara"
#endif /// !defined(STARA_LIB_STARA_VERSION_NAME)

#if !defined(STARA_LIB_STARA_VERSION_MAJOR)
#define STARA_LIB_STARA_VERSION_MAJOR 0
#endif /// !defined(STARA_LIB_STARA_VERSION_MAJOR)

#if !defined(STARA_LIB_STARA_VERSION_MINOR)
#define STARA_LIB_STARA_VERSION_MINOR 0
#endif /// !defined(STARA_LIB_STARA_VERSION_MINOR)

#if !defined(STARA_LIB_STARA_VERSION_RELEASE)
#define STARA_LIB_STARA_VERSION_RELEASE 0
#endif /// !defined(STARA_LIB_STARA_VERSION_RELEASE)

namespace stara {
namespace lib {
namespace stara {

namespace which {
typedef lib::Version VersionImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Version: virtual public VersionImplements {
public:
    typedef VersionImplements Implements;
    Version() {
    }
    virtual const char_t* Name() const {
        return STARA_LIB_STARA_VERSION_NAME;
    }
    virtual unsigned Major() const {
        return STARA_LIB_STARA_VERSION_MAJOR;
    }
    virtual unsigned Minor() const {
        return STARA_LIB_STARA_VERSION_MINOR;
    }
    virtual unsigned Release() const {
        return STARA_LIB_STARA_VERSION_RELEASE;
    }
}; /// class _EXPORT_CLASS Version
} /// namespace which

///////////////////////////////////////////////////////////////////////
///  Class: Version
///////////////////////////////////////////////////////////////////////
const lib::Version& Version::Which() {
    static const which::Version version;
    return version;
}

} /// namespace stara
} /// namespace lib
} /// namespace stara
