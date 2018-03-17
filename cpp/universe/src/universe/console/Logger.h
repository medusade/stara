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
//   File: Logger.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_CONSOLE_LOGGER_H
#define _UNIVERSE_CONSOLE_LOGGER_H

#include "universe/logger/Interface.h"
#include "universe/console/Io.h"

namespace universe {
namespace console {

typedef logger::BaseImplements LoggerImplements;
typedef logger::Base LoggerExtends;
//
// Class: Logger
//
class Logger: virtual public LoggerImplements, public LoggerExtends {
public:
   typedef LoggerImplements Implements;
   typedef LoggerExtends Extends;

   Logger(Io& io): Extends(io), _io(io) {
   }

   virtual void log(const char* chars, size_t length) {
      if ((chars) && (length)) {
         for (char c = *(chars); length; --length, c = *(++chars)) {
            _io.err(&c, 1);
         }
      }
   }
   virtual void log(const char* chars) {
      _io.err(chars);
   }
   virtual void logLn() {
      _io.errln();
   }
   
protected:
   Io& _io;
};

} // namespace console 
} // namespace universe 

#endif // _UNIVERSE_CONSOLE_LOGGER_H
