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
//   File: Interface.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_LOGGER_INTERFACE_H
#define _UNIVERSE_LOGGER_INTERFACE_H

#include "universe/logger/Output.h"

namespace universe {
namespace logger {

typedef logger::Output InterfaceImplements;
//
// Class: Interface
//
class _EXPORT_CLASS Interface: virtual public InterfaceImplements {
public:
   typedef InterfaceImplements Implements;

   virtual bool init() {
       return true;
   }
   virtual bool fini() {
       return true;
   }

   virtual bool lock() {
       return true;
   }
   virtual bool unlock() {
       return true;
   }

   using Implements::log;
   virtual void log
   (const Level& _level, const Location& _location, const Message& _message) {
       Lock lock(*this);
       if ((this->isEnabledFor(_level))) {
           log(_location);
           log(_message);
           logLn();
       }
   }
   virtual void log
   (const Level& _level, const Function& _function, const Message& _message) {
       Lock lock(*this);
       if ((this->isEnabledFor(_level))) {
           log(_function);
           log(_message);
           logLn();
       }
   }
   virtual void log
   (const Level& _level, const Message& _message) {
       Lock lock(*this);
       if ((this->isEnabledFor(_level))) {
           log(_message);
           logLn();
       }
   }

   static Interface* setDefault(Interface* to) {
       theDefault() = to;
       return theDefault();
   }
   static Interface* getDefault() {
       return theDefault();
   }
protected:
   static Interface*& theDefault() {
       static Interface* theDefault = 0;
       return theDefault;
   }
};

typedef Interface BaseImplements;
typedef Base BaseExtends;
//
// Class: Base
//
class _EXPORT_CLASS Base: virtual public BaseImplements, public BaseExtends {
public:
   typedef BaseImplements Implements;
   typedef BaseExtends Extends;
   typedef Base Derives;

   Base(Locked& locked, Level level): m_locked(locked), m_level(level) {
        Interface*& theDefault = Derives::theDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(Locked& locked): m_locked(locked), m_level(enabledForDefault()) {
        Interface*& theDefault = Derives::theDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(Level level): m_locked(*this), m_level(level) {
        Interface*& theDefault = Derives::theDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(const Base& copy): m_locked(copy.m_locked), m_level(copy.m_level) {
        Interface*& theDefault = Derives::theDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(): m_locked(*this), m_level(enabledForDefault()) {
        Interface*& theDefault = Derives::theDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    virtual ~Base() {
        Interface*& theDefault = Derives::theDefault();
        if ((theDefault) && (theDefault != this)) {
            theDefault = 0;
        }
    }

    virtual Level enableFor(const Level& _level) {
        Level enabledFor = this->enabledFor();
        m_level = _level;
        return enabledFor;
    }
    virtual Level enabledFor() const {
        return m_level;
    }
    virtual bool isEnabledFor(const Level& _level) const {
        if ((_level) && (_level == (_level & m_level))) {
            return true;
        }
        return false;
    }

    virtual bool lock() {
        if (&m_locked != this) {
            return m_locked.lock(); }
        return true;
    }
    virtual bool unlock() {
        if (&m_locked != this) {
            return m_locked.unlock(); }
        return true;
    }
    virtual Locked& locked() const {
        if (&m_locked != this) {
            return ((Locked&)m_locked); }
        return ((Locked&)*this);
    }

protected:
    Locked& m_locked;
    Level m_level;
};

} // namespace logger 
} // namespace universe 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define INIT_LOGGER(logger_) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)) { logger->init(); } }

#define FINI_LOGGER(logger_) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)) { logger->fini(); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define SET_LOGGER_LEVEL(logger_, level_) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)) { logger->enableFor(level_); } }

#define GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabledFor()):(::universe::logger::level\
(::universe::logger::LevelsNone)))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define LOG_LOCATION(logger_, level_, message_) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)?(logger->isEnabledFor(level_)):(false)) {\
   ::universe::logger::Message message; \
   logger->log(level_, LOGGER_LOCATION, message << message_); } }

#define LOG_FUNCTION(logger_, level_, message_) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)?(logger->isEnabledFor(level_)):(false)) {\
   ::universe::logger::Message message; \
   logger->log(level_, LOGGER_FUNCTION, message << message_); } }

#define LOG_PLAIN(logger_, level_, message_) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)?(logger->isEnabledFor(level_)):(false)) {\
   ::universe::logger::Message message; \
   logger->log(level_, message << message_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define IF_LOG_LOCATION(logger_, level_, message_) { \
if ((this->isLogged())) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)?(logger->isEnabledFor(level_)):(false)) {\
   ::universe::logger::Message message; \
   logger->log(level_, LOGGER_LOCATION, message << message_); } } }

#define IF_LOG_FUNCTION(logger_, level_, message_) { \
if ((this->isLogged())) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)?(logger->isEnabledFor(level_)):(false)) {\
   ::universe::logger::Message message; \
   logger->log(level_, LOGGER_FUNCTION, message << message_); } } }

#define IF_LOG_PLAIN(logger_, level_, message_) { \
if ((this->isLogged())) { \
::universe::logger::Interface* logger = logger_; \
if ((logger)?(logger->isEnabledFor(level_)):(false)) {\
   ::universe::logger::Message message; \
   logger->log(level_, message << message_); } } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(USE_LOGGER)
#define DEFAULT_LOGGER ::universe::logger::Interface::getDefault()
#endif // !defined(USE_LOGGER)
#define SET_DEFAULT_LOGGER(to) ::universe::logger::Interface::setDefault(to)

#define LOGGER_INIT() INIT_LOGGER(DEFAULT_LOGGER)
#define LOGGER_FINI() FINI_LOGGER(DEFAULT_LOGGER)

#define SET_LOGGING_LEVEL(level)  SET_LOGGER_LEVEL(DEFAULT_LOGGER, level)
#define GET_LOGGING_LEVEL(level)  (level = GET_LOGGER_LEVEL(DEFAULT_LOGGER))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define LOG_LOCATION_FATAL(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelFatal, message)
#define LOG_LOCATION_ERROR(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelError, message)
#define LOG_LOCATION_WARN(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelWarn, message)
#define LOG_LOCATION_INFO(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelInfo, message)
#define LOG_LOCATION_DEBUG(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelDebug, message)
#define LOG_LOCATION_TRACE(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelTrace, message)

#define LOG_FUNCTION_FATAL(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelFatal, message)
#define LOG_FUNCTION_ERROR(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelError, message)
#define LOG_FUNCTION_WARN(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelWarn, message)
#define LOG_FUNCTION_INFO(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelInfo, message)
#define LOG_FUNCTION_DEBUG(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelDebug, message)
#define LOG_FUNCTION_TRACE(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelTrace, message)

#define LOG_PLAIN_FATAL(message) LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelFatal, message)
#define LOG_PLAIN_ERROR(message) LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelError, message)
#define LOG_PLAIN_WARN(message) LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelWarn, message)
#define LOG_PLAIN_INFO(message) LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelInfo, message)
#define LOG_PLAIN_DEBUG(message) LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelDebug, message)
#define LOG_PLAIN_TRACE(message) LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelTrace, message)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define LOG_LOCATION_DEBUG_TRACE(cond, message) \
{ if ((cond)) { LOG_LOCATION_DEBUG(message); } \
  else { LOG_LOCATION_TRACE(message); } }

#define LOG_FUNCTION_DEBUG_TRACE(cond, message) \
{ if ((cond)) { LOG_FUNCTION_DEBUG(message); } \
  else { LOG_FUNCTION_TRACE(message); } }

#define LOG_PLAIN_DEBUG_TRACE(cond, message) \
{ if ((cond)) { LOG_PLAIN_DEBUG(message); } \
  else { LOG_PLAIN_TRACE(message); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define IF_LOG_LOCATION_FATAL(message) IF_LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelFatal, message)
#define IF_LOG_LOCATION_ERROR(message) IF_LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelError, message)
#define IF_LOG_LOCATION_WARN(message) IF_LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelWarn, message)
#define IF_LOG_LOCATION_INFO(message) IF_LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelInfo, message)
#define IF_LOG_LOCATION_DEBUG(message) IF_LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelDebug, message)
#define IF_LOG_LOCATION_TRACE(message) IF_LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::LevelTrace, message)

#define IF_LOG_FUNCTION_FATAL(message) IF_LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelFatal, message)
#define IF_LOG_FUNCTION_ERROR(message) IF_LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelError, message)
#define IF_LOG_FUNCTION_WARN(message) IF_LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelWarn, message)
#define IF_LOG_FUNCTION_INFO(message) IF_LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelInfo, message)
#define IF_LOG_FUNCTION_DEBUG(message) IF_LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelDebug, message)
#define IF_LOG_FUNCTION_TRACE(message) IF_LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::LevelTrace, message)

#define IF_LOG_PLAIN_FATAL(message) IF_LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelFatal, message)
#define IF_LOG_PLAIN_ERROR(message) IF_LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelError, message)
#define IF_LOG_PLAIN_WARN(message) IF_LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelWarn, message)
#define IF_LOG_PLAIN_INFO(message) IF_LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelInfo, message)
#define IF_LOG_PLAIN_DEBUG(message) IF_LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelDebug, message)
#define IF_LOG_PLAIN_TRACE(message) IF_LOG_PLAIN(DEFAULT_LOGGER, ::universe::logger::LevelTrace, message)

#if defined(PLAIN_LOGGING)
#define LOG LOG_PLAIN
#define LOG_FATAL LOG_PLAIN_FATAL
#define LOG_ERROR LOG_PLAIN_ERROR
#define LOG_WARN  LOG_PLAIN_WARN
#define LOG_INFO  LOG_PLAIN_INFO
#define LOG_DEBUG LOG_PLAIN_DEBUG
#define LOG_TRACE LOG_PLAIN_TRACE
#define LOG_DEBUG_TRACE LOG_PLAIN_DEBUG_TRACE
#else // defined(PLAIN_LOGGING)
#if defined(FUNCTION_LOGGING)
#define LOG LOG_FUNCTION
#define LOG_FATAL LOG_FUNCTION_FATAL
#define LOG_ERROR LOG_FUNCTION_ERROR
#define LOG_WARN  LOG_FUNCTION_WARN
#define LOG_INFO  LOG_FUNCTION_INFO
#define LOG_DEBUG LOG_FUNCTION_DEBUG
#define LOG_TRACE LOG_FUNCTION_TRACE
#define LOG_DEBUG_TRACE LOG_FUNCTION_DEBUG_TRACE
#else // defined(FUNCTION_LOGGING)
#define LOG LOG_LOCATION
#define LOG_FATAL LOG_LOCATION_FATAL
#define LOG_ERROR LOG_LOCATION_ERROR
#define LOG_WARN  LOG_LOCATION_WARN
#define LOG_INFO  LOG_LOCATION_INFO
#define LOG_DEBUG LOG_LOCATION_DEBUG
#define LOG_TRACE LOG_LOCATION_TRACE
#define LOG_DEBUG_TRACE LOG_LOCATION_DEBUG_TRACE
#endif // defined(FUNCTION_LOGGING)
#endif // defined(PLAIN_LOGGING)

#if defined(PLAIN_LOGGING)
#define IF_LOG IF_LOG_PLAIN
#define IF_LOG_FATAL IF_LOG_PLAIN_FATAL
#define IF_LOG_ERROR IF_LOG_PLAIN_ERROR
#define IF_LOG_WARN  IF_LOG_PLAIN_WARN
#define IF_LOG_INFO  IF_LOG_PLAIN_INFO
#define IF_LOG_DEBUG IF_LOG_PLAIN_DEBUG
#define IF_LOG_TRACE IF_LOG_PLAIN_TRACE
#else // defined(PLAIN_LOGGING)
#if defined(FUNCTION_LOGGING)
#define IF_LOG IF_LOG_FUNCTION
#define IF_LOG_FATAL IF_LOG_FUNCTION_FATAL
#define IF_LOG_ERROR IF_LOG_FUNCTION_ERROR
#define IF_LOG_WARN  IF_LOG_FUNCTION_WARN
#define IF_LOG_INFO  IF_LOG_FUNCTION_INFO
#define IF_LOG_DEBUG IF_LOG_FUNCTION_DEBUG
#define IF_LOG_TRACE IF_LOG_FUNCTION_TRACE
#else // defined(FUNCTION_LOGGING)
#define IF_LOG IF_LOG_LOCATION
#define IF_LOG_FATAL IF_LOG_LOCATION_FATAL
#define IF_LOG_ERROR IF_LOG_LOCATION_ERROR
#define IF_LOG_WARN  IF_LOG_LOCATION_WARN
#define IF_LOG_INFO  IF_LOG_LOCATION_INFO
#define IF_LOG_DEBUG IF_LOG_LOCATION_DEBUG
#define IF_LOG_TRACE IF_LOG_LOCATION_TRACE
#endif // defined(FUNCTION_LOGGING)
#endif // defined(PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define LOG_LOCATION_MESSAGE_FATAL(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::MessageLevelFatal, message)
#define LOG_LOCATION_MESSAGE_ERROR(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::MessageLevelError, message)
#define LOG_LOCATION_MESSAGE_WARN(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::MessageLevelWarn, message)
#define LOG_LOCATION_MESSAGE_INFO(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::MessageLevelInfo, message)
#define LOG_LOCATION_MESSAGE_DEBUG(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::MessageLevelDebug, message)
#define LOG_LOCATION_MESSAGE_TRACE(message) LOG_LOCATION(DEFAULT_LOGGER, ::universe::logger::MessageLevelTrace, message)

#define LOG_FUNCTION_MESSAGE_FATAL(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::MessageLevelFatal, message)
#define LOG_FUNCTION_MESSAGE_ERROR(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::MessageLevelError, message)
#define LOG_FUNCTION_MESSAGE_WARN(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::MessageLevelWarn, message)
#define LOG_FUNCTION_MESSAGE_INFO(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::MessageLevelInfo, message)
#define LOG_FUNCTION_MESSAGE_DEBUG(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::MessageLevelDebug, message)
#define LOG_FUNCTION_MESSAGE_TRACE(message) LOG_FUNCTION(DEFAULT_LOGGER, ::universe::logger::MessageLevelTrace, message)

#define LOG_PLAIN_MESSAGE_FATAL(message) LOG(DEFAULT_LOGGER, ::universe::logger::MessageLevelFatal, message)
#define LOG_PLAIN_MESSAGE_ERROR(message) LOG(DEFAULT_LOGGER, ::universe::logger::MessageLevelError, message)
#define LOG_PLAIN_MESSAGE_WARN(message) LOG(DEFAULT_LOGGER, ::universe::logger::MessageLevelWarn, message)
#define LOG_PLAIN_MESSAGE_INFO(message) LOG(DEFAULT_LOGGER, ::universe::logger::MessageLevelInfo, message)
#define LOG_PLAIN_MESSAGE_DEBUG(message) LOG(DEFAULT_LOGGER, ::universe::logger::MessageLevelDebug, message)
#define LOG_PLAIN_MESSAGE_TRACE(message) LOG(DEFAULT_LOGGER, ::universe::logger::MessageLevelTrace, message)

#if defined(PLAIN_MESSAGE_LOGGING)
#define LOG_MESSAGE_FATAL LOG_PLAIN_MESSAGE_FATAL
#define LOG_MESSAGE_ERROR LOG_PLAIN_MESSAGE_ERROR
#define LOG_MESSAGE_WARN  LOG_PLAIN_MESSAGE_WARN
#define LOG_MESSAGE_INFO  LOG_PLAIN_MESSAGE_INFO
#define LOG_MESSAGE_DEBUG LOG_PLAIN_MESSAGE_DEBUG
#define LOG_MESSAGE_TRACE LOG_PLAIN_MESSAGE_TRACE
#else // defined(PLAIN_MESSAGE_LOGGING)
#if defined(LOCATION_MESSAGE_LOGGING)
#define LOG_MESSAGE_FATAL LOG_LOCATION_MESSAGE_FATAL
#define LOG_MESSAGE_ERROR LOG_LOCATION_MESSAGE_ERROR
#define LOG_MESSAGE_WARN  LOG_LOCATION_MESSAGE_WARN
#define LOG_MESSAGE_INFO  LOG_LOCATION_MESSAGE_INFO
#define LOG_MESSAGE_DEBUG LOG_LOCATION_MESSAGE_DEBUG
#define LOG_MESSAGE_TRACE LOG_LOCATION_MESSAGE_TRACE
#else // defined(LOCATION_MESSAGE_LOGGING)
#define LOG_MESSAGE_FATAL LOG_FUNCTION_MESSAGE_FATAL
#define LOG_MESSAGE_ERROR LOG_FUNCTION_MESSAGE_ERROR
#define LOG_MESSAGE_WARN  LOG_FUNCTION_MESSAGE_WARN
#define LOG_MESSAGE_INFO  LOG_FUNCTION_MESSAGE_INFO
#define LOG_MESSAGE_DEBUG LOG_FUNCTION_MESSAGE_DEBUG
#define LOG_MESSAGE_TRACE LOG_FUNCTION_MESSAGE_TRACE
#endif // defined(LOCATION_MESSAGE_LOGGING)
#endif // defined(PLAIN_MESSAGE_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#ifndef LOG_LOCATION
#define LOG_LOCATION_FATAL(...)
#define LOG_LOCATION_ERROR(...)
#define LOG_LOCATION_WARN(...)
#define LOG_LOCATION_INFO(...)
#define LOG_LOCATION_DEBUG(...)
#define LOG_LOCATION_TRACE(...)
#endif // LOG_LOCATION

#ifndef LOG_FUNCTION
#define LOG_FUNCTION_FATAL(...)
#define LOG_FUNCTION_ERROR(...)
#define LOG_FUNCTION_WARN(...)
#define LOG_FUNCTION_INFO(...)
#define LOG_FUNCTION_DEBUG(...)
#define LOG_FUNCTION_TRACE(...)
#endif // LOG_FUNCTION

#ifndef LOG_PLAIN
#define LOG_PLAIN_FATAL(...)
#define LOG_PLAIN_ERROR(...)
#define LOG_PLAIN_WARN(...)
#define LOG_PLAIN_INFO(...)
#define LOG_PLAIN_DEBUG(...)
#define LOG_PLAIN_TRACE(...)
#endif // LOG_PLAIN

#ifndef LOG
#define LOG_FATAL(...)
#define LOG_ERROR(...)
#define LOG_WARN(...)
#define LOG_INFO(...)
#define LOG_DEBUG(...)
#define LOG_TRACE(...)
#endif // LOG

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#ifndef IF_LOG_LOCATION
#define IF_LOG_LOCATION_FATAL(...)
#define IF_LOG_LOCATION_ERROR(...)
#define IF_LOG_LOCATION_WARN(...)
#define IF_LOG_LOCATION_INFO(...)
#define IF_LOG_LOCATION_DEBUG(...)
#define IF_LOG_LOCATION_TRACE(...)
#endif // IF_LOG_LOCATION

#ifndef IF_LOG_FUNCTION
#define IF_LOG_FUNCTION_FATAL(...)
#define IF_LOG_FUNCTION_ERROR(...)
#define IF_LOG_FUNCTION_WARN(...)
#define IF_LOG_FUNCTION_INFO(...)
#define IF_LOG_FUNCTION_DEBUG(...)
#define IF_LOG_FUNCTION_TRACE(...)
#endif // IF_LOG_FUNCTION

#ifndef IF_LOG_PLAIN
#define IF_LOG_PLAIN_FATAL(...)
#define IF_LOG_PLAIN_ERROR(...)
#define IF_LOG_PLAIN_WARN(...)
#define IF_LOG_PLAIN_INFO(...)
#define IF_LOG_PLAIN_DEBUG(...)
#define IF_LOG_PLAIN_TRACE(...)
#endif // IF_LOG_PLAIN

#ifndef IF_LOG
#define IF_LOG_FATAL(...)
#define IF_LOG_ERROR(...)
#define IF_LOG_WARN(...)
#define IF_LOG_INFO(...)
#define IF_LOG_DEBUG(...)
#define IF_LOG_TRACE(...)
#endif // IF_LOG

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _UNIVERSE_LOGGER_INTERFACE_H
