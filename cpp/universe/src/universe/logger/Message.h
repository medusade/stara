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
//   File: Message.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_LOGGER_MESSAGE_H
#define _UNIVERSE_LOGGER_MESSAGE_H

#include "universe/logger/Level.h"

namespace universe {
namespace logger {

typedef String::Implements FunctionImplements;
typedef String FunctionExtends;
//
//  Class: Function
//
class _EXPORT_CLASS Function
: virtual public FunctionImplements, public FunctionExtends {
public:
   typedef FunctionImplements Implements;
   typedef FunctionExtends Extends;
   Function(const String& name): Extends(name) {
   }
   Function(const char* name): Extends(name) {
   }
   Function(const Function& copy): Extends(copy) {
   }
};

typedef String::Implements LocationImplements;
typedef String LocationExtends;
//
// Class: Location
//
class _EXPORT_CLASS Location
: virtual public LocationImplements, public LocationExtends {
public:
   typedef LocationImplements Implements;
   typedef LocationExtends Extends;
   Location
   (const String& functionName, const String& fileName, size_t lineNumber)
   : _functionName(functionName),
     _fileName(fileName), _lineNumber(lineNumber) {
   }
   Location
   (const char* functionName, const char* fileName, size_t lineNumber)
   : _functionName(functionName),
     _fileName(fileName), _lineNumber(lineNumber) {
   }
   Location(const Location& copy)
   : _functionName(copy._functionName),
     _fileName(copy._fileName), _lineNumber(copy._lineNumber) {
   }
   inline String functionName() const { return _functionName; }
   inline String fileName() const { return _fileName; }
   inline String lineNumber() const {
       String s; s.appendUnsigned(_lineNumber);
       return s;
   }
protected:
   String _functionName;
   String _fileName;
   size_t _lineNumber;
};

typedef String::Implements MessageImplements;
typedef String MessageExtends;
//
// Class: Message
//
class _EXPORT_CLASS Message
: virtual public MessageImplements, public MessageExtends {
public:
   typedef MessageImplements Implements;
   typedef MessageExtends Extends;
   Message() {}
   Message& operator << (const Extends& str) { 
      append(str); 
      return *this; 
   }
   Message& operator << (const char* chars) { 
      append(chars); 
      return *this; 
   }
   Message& operator << (int i) {
      appendSigned(i);
      return *this;
   }
};

} // namespace logger 
} // namespace universe 

#endif // _UNIVERSE_LOGGER_MESSAGE_H
