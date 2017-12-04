//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: Enabled.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_LOGGER_ENABLED_H
#define _UNIVERSE_LOGGER_ENABLED_H

#include "universe/logger/Level.h"

namespace universe {
namespace logger {

typedef Locked EnabledImplements;
//
//  Class: Enabled
//
class _EXPORT_CLASS Enabled: virtual public EnabledImplements {
public:
    typedef EnabledImplements Implements;

    virtual Level enableFor(const Level& level) {
        Level enabledFor = this->enabledFor();
        return enabledFor;
    }
    virtual Level enabledFor() const {
        Level enabledFor = this->enabledForDefault();
        return enabledFor;
    }
    virtual bool isEnabledFor(const Level& _level) const {
        Level enabledFor = this->enabledFor();
        if ((_level) && (_level == (_level & enabledFor))) {
            return true;
        }
        return false;
    }
    virtual Level enabledForDefault() const {
#if defined(TRACE_BUILD)
        return LevelsTrace;
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
        return LevelsDebug;
#else // defined(DEBUG_BUILD)
        return LevelsError;
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
    }
};

} // namespace logger 
} // namespace universe 

#endif // _UNIVERSE_LOGGER_ENABLED_H
