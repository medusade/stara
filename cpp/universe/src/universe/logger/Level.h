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
//   File: Level.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_LOGGER_LEVEL_H
#define _UNIVERSE_LOGGER_LEVEL_H

#include "universe/base/Base.h"

namespace universe {
namespace logger {

//
// Enum: Level
//
typedef unsigned Level;
enum {
    LevelNone  = 0,

    LevelFatal = 1,
    LevelError = (LevelFatal << 1),
    LevelWarn  = (LevelError << 1),
    LevelInfo  = (LevelWarn << 1),
    LevelDebug = (LevelInfo << 1),
    LevelTrace = (LevelDebug << 1),

    LevelAll   = ((LevelTrace << 1) - 1),

    MessageLevelNone  = 0,

    MessageLevelFatal = (LevelTrace << 1),
    MessageLevelError = (MessageLevelFatal << 1),
    MessageLevelWarn  = (MessageLevelError << 1),
    MessageLevelInfo  = (MessageLevelWarn << 1),
    MessageLevelDebug = (MessageLevelInfo << 1),
    MessageLevelTrace = (MessageLevelDebug << 1),

    MessageLevelAll   = ((LevelAll << LevelTrace))
};
//
// Enum: Levels
//
typedef Level Levels;
enum {
    LevelsNone  = 0,

    LevelsFatal = 1,
    LevelsError = (((LevelsFatal + 1) << 1) - 1),
    LevelsWarn  = (((LevelsError + 1) << 1) - 1),
    LevelsInfo  = (((LevelsWarn + 1) << 1) - 1),
    LevelsDebug = (((LevelsInfo + 1) << 1) - 1),
    LevelsTrace = (((LevelsDebug + 1) << 1) - 1),

    LevelsAll   = LevelsTrace,

    MessageLevelsNone  = 0,

    MessageLevelsFatal = (((LevelsFatal) << LevelTrace)),
    MessageLevelsError = (((LevelsError) << LevelTrace)),
    MessageLevelsWarn  = (((LevelsWarn) << LevelTrace)),
    MessageLevelsInfo  = (((LevelsInfo) << LevelTrace)),
    MessageLevelsDebug = (((LevelsDebug) << LevelTrace)),
    MessageLevelsTrace = (((LevelsTrace) << LevelTrace)),

    MessageLevelsAll   = MessageLevelsTrace
};

} // namespace logger 
} // namespace universe 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define LOGGING_LEVELS ::universe::logger::Level
#define LOGGING_LEVELS_ALL ::universe::logger::LevelsAll
#define LOGGING_LEVELS_NONE ::universe::logger::LevelsNone
#define LOGGING_LEVELS_FATAL ::universe::logger::LevelsFatal
#define LOGGING_LEVELS_ERROR ::universe::logger::LevelsError
#define LOGGING_LEVELS_WARN ::universe::logger::LevelsWarn
#define LOGGING_LEVELS_INFO ::universe::logger::LevelsInfo
#define LOGGING_LEVELS_DEBUG ::universe::logger::LevelsDebug
#define LOGGING_LEVELS_TRACE ::universe::logger::LevelsTrace

#define LOGGING_MESSAGE_LEVELS ::universe::logger::MessageLevel
#define LOGGING_MESSAGE_LEVELS_ALL ::universe::logger::MessageLevelsAll
#define LOGGING_MESSAGE_LEVELS_NONE ::universe::logger::MessageLevelsNone
#define LOGGING_MESSAGE_LEVELS_FATAL ::universe::logger::MessageLevelsFatal
#define LOGGING_MESSAGE_LEVELS_ERROR ::universe::logger::MessageLevelsError
#define LOGGING_MESSAGE_LEVELS_WARN ::universe::logger::MessageLevelsWarn
#define LOGGING_MESSAGE_LEVELS_INFO ::universe::logger::MessageLevelsInfo
#define LOGGING_MESSAGE_LEVELS_DEBUG ::universe::logger::MessageLevelsDebug
#define LOGGING_MESSAGE_LEVELS_TRACE ::universe::logger::MessageLevelsTrace

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(LOGGING_LEVELS_DEFAULT)
#if defined(TRACE_BUILD)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_TRACE
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_DEBUG
#else // defined(DEBUG_BUILD)
#define LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_ERROR
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
#endif // !defined(LOGGING_LEVELS_DEFAULT)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _UNIVERSE_LOGGER_LEVEL_H
