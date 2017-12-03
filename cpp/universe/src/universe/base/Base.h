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
//   File: Base.h
//
// Author: $author$
//   Date: 12/2/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_BASE_BASE_H
#define _UNIVERSE_BASE_BASE_H

#include "xos/platform/platform.hpp"
#include <stdarg.h>
#include <sstream>
#include <string>

namespace universe {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: ImplementBase
//
class ImplementBase
{
public:
   virtual ~ImplementBase()
   {
   }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: Base
//
class Base
: virtual public ImplementBase
{
public:
   typedef ImplementBase Implements;

   Base(const Base& copy)
   {
   }
   Base()
   {
   }
   virtual ~Base()
   {
   }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: StringT
//
template 
<typename TChar = char, 
 class TString = ::std::basic_string<TChar>,
 class TStringStream = ::std::basic_stringstream<TChar>,
 class TImplements = ImplementBase, class TExtends = TString>

class StringT
: virtual public TImplements, public TExtends
{
public:
   typedef TImplements Implements;
   typedef TExtends Extends;

   StringT(const TChar* chars, size_t length): Extends(chars, length)
   {
   }
   StringT(const TChar* chars): Extends(chars)
   {
   }
   StringT(const Extends& copy): Extends(copy)
   {
   }
   StringT(const StringT& copy): Extends(copy)
   {
   }
   StringT()
   {
   }
   virtual ~StringT()
   {
   }
   
   virtual StringT& assignSigned(signed to) 
   {
      this->clear();
      this->appendSigned(to);
      return *this;
   }
   virtual StringT& assignUnsigned(unsigned to) 
   {
      this->clear();
      this->appendUnsigned(to);
      return *this;
   }

   virtual StringT& appendSigned(signed to) 
   {
      TStringStream ss;
      ss << to;
      this->append(ss.str());
      return *this;
   }
   virtual StringT& appendUnsigned(unsigned to) 
   {
      TStringStream ss;
      ss << to;
      this->append(ss.str());
      return *this;
   }

   virtual signed toSigned() const 
   {
      signed to = 0;      
      TStringStream(*this) >> to;
      return to;
   }
   virtual unsigned toUnsigned() const 
   {
      unsigned to = 0;      
      TStringStream(*this) >> to;
      return to;
   }

   virtual StringT& operator << (signed to) 
   {
      this->appendSigned(to);
      return *this;
   }
   virtual StringT& operator << (unsigned to) 
   {
      this->appendUnsigned(to);
      return *this;
   }
   
   virtual operator signed() const 
   {
      return this->toSigned();
   }
   virtual operator unsigned() const 
   {
      return this->toUnsigned();
   }
};
typedef StringT<char> String;
typedef StringT<tchar_t> TString;
typedef StringT<wchar_t> WString;

typedef StringT<byte_t> ByteString;
typedef StringT<word_t> WordString;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Enum: ExceptionReason
//
enum ExceptionReason {
    ExceptionFailed
};

//
// Function: ExceptionToChars
//
inline const char* ExceptionToChars(ExceptionReason reason) 
{
   switch (reason) {
   case ExceptionFailed: return "ExceptionFailed";
   }
   return "Unknown";
}

//
// Class: ExceptionT
//
template 
<typename TReason = ExceptionReason, 
 typename TChar = char, class TString = ::std::basic_string<TChar>,
 class TImplements = ImplementBase, class TExtends = Base>

class ExceptionT
: virtual public TImplements, public TExtends
{
public:
   typedef TImplements Implements;
   typedef TExtends Extends;

   ExceptionT(TReason reason): _reason(reason)
   {
   }
   ExceptionT(const ExceptionT& copy)
   {
   }
   virtual ~ExceptionT()
   {
   }

   virtual TReason setReason(TReason to) 
   {
      _reason = to;
      return _reason;
   }
   virtual TReason reason() const 
   {
      return _reason;
   }
   virtual TString reasonToString() const 
   {
      TString to(this->reasonToChars());
      return to;
   }
   virtual const TChar* reasonToChars() const 
   {
      return this->toChars();
   }
   virtual const TChar* toChars() const 
   {
      const TChar& chars = ExceptionToChars(_reason);
      return chars;
   }
   virtual operator const TChar*() const 
   {
      return this->toChars();
   }

protected:
   TReason _reason;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
} // namespace universe 

#endif // _UNIVERSE_BASE_BASE_H
