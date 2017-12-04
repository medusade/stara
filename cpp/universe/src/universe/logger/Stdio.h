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
//   File: Stdio.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_LOGGER_STDIO_H
#define _UNIVERSE_LOGGER_STDIO_H

#include "universe/logger/Message.h"
#include <stdio.h>
#include <iostream>

namespace universe {
namespace logger {

} // namespace logger 
} // namespace universe 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(__LOGGER_FUNCTION__)
#define __LOGGER_FUNCTION__ __FUNCTION__
#endif // !defined(__LOGGER_FUNCTION__)

#if !defined(LOGGER_FUNCTION)
#define LOGGER_FUNCTION \
    ::universe::logger::Function(__LOGGER_FUNCTION__)
#endif // !defined(LOGGER_LOCATION)

#if !defined(LOGGER_LOCATION)
#define LOGGER_LOCATION \
    ::universe::logger::Location(__LOGGER_FUNCTION__, __FILE__, __LINE__)
#endif // !defined(LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define COSTREAM_LOG_PLAIN(ostream_, message_) \
{ ::universe::logger::Message message; \
  ostream_ << message << message_ << "\n"; }

#define COSTREAM_LOG_FUNCTION(ostream_, message_) \
{ ::universe::logger::Message message; \
  ostream_ << LOGGER_FUNCTION << ": " << message << message_ << "\n"; }

#define COSTREAM_LOG_LOCATION(ostream_, message_) \
{ ::universe::logger::Location location = LOGGER_LOCATION; \
  ::universe::logger::Message message; \
  ostream_ <<  location.fileName().chars() << "[" <<  location.lineNumber().chars() << "] " \
  <<  location.functionName().chars() << ": " << message << message_ << "\n"; }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define STDSTREAM_LOG_PLAIN(stream_, message_) \
{ ::universe::logger::Message message; message << message_; \
  fprintf(stream_, "%s\n", message.chars()); }

#define STDSTREAM_LOG_FUNCTION(stream_, message_) \
{ ::universe::logger::Function function = LOGGER_FUNCTION; \
  ::universe::logger::Message message; message << message_; \
  fprintf(stream_, "%s: %s\n", function.chars(), message.chars()); }

#define STDSTREAM_LOG_LOCATION(stream_, message_) \
{ ::universe::logger::Location location = LOGGER_LOCATION; \
  ::universe::logger::Message message; message << message_; \
  fprintf(stream_, "%s[%s] %s: %s\n", location.fileName().chars(), \
  location.lineNumber().chars(), location.functionName().chars(), message.chars()); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CERR_LOG_PLAIN(message_) COSTREAM_LOG_PLAIN(::std::cerr, message_)
#define STDERR_LOG_PLAIN(message_) STDSTREAM_LOG_PLAIN(stderr, message_)
#define CERR_LOG_FUNCTION(message_) COSTREAM_LOG_FUNCTION(::std::cerr, message_)
#define STDERR_LOG_FUNCTION(message_) STDSTREAM_LOG_FUNCTION(stderr, message_)
#define CERR_LOG_LOCATION(message_) COSTREAM_LOG_LOCATION(::std::cerr, message_)
#define STDERR_LOG_LOCATION(message_) STDSTREAM_LOG_LOCATION(stderr, message_)

#if defined(PLAIN_LOGGING)
#define CERR_LOG CERR_LOG_PLAIN
#define STDERR_LOG STDERR_LOG_PLAIN
#else // defined(PLAIN_LOGGING)
#if defined(FUNCTION_LOGGING)
#define CERR_LOG CERR_LOG_FUNCTION
#define STDERR_LOG STDERR_LOG_FUNCTION
#else // defined(FUNCTION_LOGGING)
#define CERR_LOG CERR_LOG_LOCATION
#define STDERR_LOG STDERR_LOG_LOCATION
#endif // defined(FUNCTION_LOGGING)
#endif // defined(PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if defined(TRACE_BUILD)
#define CERR_LOG_TRACE(message_) CERR_LOG(message_)
#define STDERR_LOG_TRACE(message_) STDERR_LOG(message_)
#define CERR_LOG_PLAIN_TRACE(message_) CERR_LOG_PLAIN(message_)
#define STDERR_LOG_PLAIN_TRACE(message_) STDERR_LOG_PLAIN(message_)
#define CERR_LOG_FUNCTION_TRACE(message_) CERR_LOG_FUNCTION(message_)
#define STDERR_LOG_FUNCTION_TRACE(message_) STDERR_LOG_FUNCTION(message_)
#define CERR_LOG_LOCATION_TRACE(message_) CERR_LOG_LOCATION(message_)
#define STDERR_LOG_LOCATION_TRACE(message_) STDERR_LOG_LOCATION(message_)
#else // defined(TRACE_BUILD)
#define CERR_LOG_TRACE(message_)
#define STDERR_LOG_TRACE(message_)
#define CERR_LOG_PLAIN_TRACE(message_)
#define STDERR_LOG_PLAIN_TRACE(message_)
#define CERR_LOG_FUNCTION_TRACE(message_)
#define STDERR_LOG_FUNCTION_TRACE(message_)
#define CERR_LOG_LOCATION_TRACE(message_)
#define STDERR_LOG_LOCATION_TRACE(message_)
#endif // defined(TRACE_BUILD)

#if defined(DEBUG_BUILD)
#define CERR_LOG_DEBUG(message_) CERR_LOG(message_)
#define STDERR_LOG_DEBUG(message_) STDERR_LOG(message_)
#define CERR_LOG_PLAIN_DEBUG(message_) CERR_LOG_PLAIN(message_)
#define STDERR_LOG_PLAIN_DEBUG(message_) STDERR_LOG_PLAIN(message_)
#define CERR_LOG_FUNCTION_DEBUG(message_) CERR_LOG_FUNCTION(message_)
#define STDERR_LOG_FUNCTION_DEBUG(message_) STDERR_LOG_FUNCTION(message_)
#define CERR_LOG_LOCATION_DEBUG(message_) CERR_LOG_LOCATION(message_)
#define STDERR_LOG_LOCATION_DEBUG(message_) STDERR_LOG_LOCATION(message_)
#else // defined(DEBUG_BUILD)
#define CERR_LOG_DEBUG(message_)
#define STDERR_LOG_DEBUG(message_)
#define CERR_LOG_FUNCTION_DEBUG(message_)
#define STDERR_LOG_FUNCTION_DEBUG(message_)
#define CERR_LOG_LOCATION_DEBUG(message_)
#define STDERR_LOG_LOCATION_DEBUG(message_)
#endif // defined(DEBUG_BUILD)

#define CERR_LOG_ERROR(message_) CERR_LOG(message_)
#define STDERR_LOG_ERROR(message_) STDERR_LOG(message_)
#define CERR_LOG_PLAIN_ERROR(message_) CERR_LOG_PLAIN(message_)
#define STDERR_LOG_PLAIN_ERROR(message_) STDERR_LOG_PLAIN(message_)
#define CERR_LOG_FUNCTION_ERROR(message_) CERR_LOG_FUNCTION(message_)
#define STDERR_LOG_FUNCTION_ERROR(message_) STDERR_LOG_FUNCTION(message_)
#define CERR_LOG_LOCATION_ERROR(message_) CERR_LOG_LOCATION(message_)
#define STDERR_LOG_LOCATION_ERROR(message_) STDERR_LOG_LOCATION(message_)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if defined(CERR_LOGGING)
#define ERR_LOG_TRACE(message_) CERR_LOG_TRACE(message_)
#define ERR_LOG_FUNCTION_TRACE(message_) CERR_LOG_FUNCTION_TRACE(message_)
#define ERR_LOG_LOCATION_TRACE(message_) CERR_LOG_LOCATION_TRACE(message_)
#define ERR_LOG_DEBUG(message_) CERR_LOG_DEBUG(message_)
#define ERR_LOG_FUNCTION_DEBUG(message_) CERR_LOG_FUNCTION_DEBUG(message_)
#define ERR_LOG_LOCATION_DEBUG(message_) CERR_LOG_LOCATION_DEBUG(message_)
#define ERR_LOG_ERROR(message_) CERR_LOG_ERROR(message_)
#define ERR_LOG_FUNCTION_ERROR(message_) CERR_LOG_FUNCTION_ERROR(message_)
#define ERR_LOG_LOCATION_ERROR(message_) CERR_LOG_LOCATION_ERROR(message_)
#else // defined(CERR_LOGGING)
#define ERR_LOG_TRACE(message_) STDERR_LOG_TRACE(message_)
#define ERR_LOG_FUNCTION_TRACE(message_) STDERR_LOG_FUNCTION_TRACE(message_)
#define ERR_LOG_LOCATION_TRACE(message_) STDERR_LOG_LOCATION_TRACE(message_)
#define ERR_LOG_DEBUG(message_) STDERR_LOG_DEBUG(message_)
#define ERR_LOG_FUNCTION_DEBUG(message_) STDERR_LOG_FUNCTION_DEBUG(message_)
#define ERR_LOG_LOCATION_DEBUG(message_) STDERR_LOG_LOCATION_DEBUG(message_)
#define ERR_LOG_ERROR(message_) STDERR_LOG_ERROR(message_)
#define ERR_LOG_FUNCTION_ERROR(message_) STDERR_LOG_FUNCTION_ERROR(message_)
#define ERR_LOG_LOCATION_ERROR(message_) STDERR_LOG_LOCATION_ERROR(message_)
#endif // defined(CERR_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _UNIVERSE_LOGGER_STDIO_H
