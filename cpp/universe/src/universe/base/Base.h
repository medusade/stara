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
inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return mseconds / 1000; }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return mseconds % 1000; }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return mseconds_mseconds(mseconds) * 1000; }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return mseconds_useconds(mseconds) * 1000; }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline mseconds_t seconds_mseconds
(seconds_t seconds) { return seconds * 1000; }

inline useconds_t nseconds_useconds
(nseconds_t nseconds) { return nseconds / 1000; }

inline mseconds_t nseconds_mseconds
(nseconds_t nseconds) { return nseconds_useconds(nseconds) / 1000; }

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
   
   virtual const char_t* hasChars(size_t& length) const {
      if ((length = this->length())) {
         return this->c_str();
      }
      return 0;
   }
   virtual const char_t* hasChars() const {
      size_t length = 0;
      return hasChars(length);
   }
   virtual const char_t* chars(size_t& length) const {
      length = this->length();
      return this->c_str();
   }
   virtual const char_t* chars() const {
      return this->c_str();
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
// Function: exceptionToChars
//
template <typename TReason>
inline const char* exceptionToChars(TReason reason) 
{
   return "ExceptionFailed";
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

   typedef TReason Status;
   typedef TReason Which;
   typedef TChar char_t;

   ExceptionT(TReason reason): _reason(reason)
   {
   }
   ExceptionT(const ExceptionT& copy)
   {
   }
   virtual ~ExceptionT()
   {
   }

   virtual Which setWhich(Which to) 
   {
      return setReason(to);
   }
   virtual Which which() const 
   {
      return reason();
   }

   virtual Status setStatus(Status to) 
   {
      return setReason(to);
   }
   virtual Status status() const 
   {
      return reason();
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
      const TChar* chars = exceptionToChars(_reason);
      return chars;
   }
   virtual operator const TChar*() const 
   {
      return this->toChars();
   }

protected:
   TReason _reason;
};
typedef ExceptionT<> Exception;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: LoggedT
//
template 
<class TImplements = ImplementBase>

class LoggedT
: virtual public TImplements
{
public:
   typedef TImplements Implements;
   
   virtual bool SetIsLogged(bool to) {
      return false;
   }
   virtual bool isLogged() const {
      return false;
   }
};
typedef LoggedT<> Logged;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Enum: LockStatus
//
enum LockStatus {
   UnlockSuccess,
   LockSuccess = UnlockSuccess,

   LockFailed,
   LockBusy,
   LockInterrupted,
   LockInvalid,

   UnlockFailed,
   UnlockBusy,
   UnlockInterrupted,
   UnlockInvalid
};

inline const char* lockStatusToChars(LockStatus status) {
   switch (status) {
   case LockSuccess: return "LockSuccess";
   case LockFailed: return "LockFailed";
   case LockBusy: return "LockBusy";
   case LockInterrupted: return "LockInterrupted";
   case LockInvalid: return "LockInvalid";

   case UnlockFailed: return "UnlockFailed";
   case UnlockBusy: return "UnlockBusy";
   case UnlockInterrupted: return "UnlockInterrupted";
   case UnlockInvalid: return "UnlockInvalid";
   }
   return "Unknown";
}

typedef Exception::Implements LockExceptionTImplements;
typedef ExceptionT<LockStatus> LockExceptionTExtends;
//
//  Class: LockExceptionT
//
template
<class TImplements = LockExceptionTImplements,
 class TExtends = LockExceptionTExtends>

class LockExceptionT: virtual public TImplements, public TExtends {
public:
   typedef TImplements Implements;
   typedef TExtends Extends;
   typedef typename Extends::char_t char_t;

  LockExceptionT(LockStatus status): Extends(status) {}
   virtual ~LockExceptionT() {}

  virtual const char_t* reasonToChars() const {
       return lockStatusToChars(this->reason());
   }
};
typedef LockExceptionT<> LockException;

typedef ImplementBase LockedTImplements;
//
//  Class: LockedT
//
template
<class TLockException = LockException,
 class TImplements = LockedTImplements>

class LockedT: virtual public TImplements {
public:
   typedef TImplements Implements;
   typedef TLockException LockException;

   virtual bool lock() { return false; }
   virtual LockStatus tryLock() { return LockFailed; }
   virtual LockStatus timedLock(mseconds_t milliseconds) { return LockFailed; }
   virtual LockStatus untimedLock() { return LockFailed; }
   virtual bool unlock() { return false; }
};
typedef LockedT<> Locked;

typedef Locked UnlockedTImplements;
//
//  Class: UnlockedT
//
template
<class TLockException = LockException,
 class TImplements = UnlockedTImplements>

class UnlockedT: virtual public TImplements {
public:
   typedef TImplements Implements;
   typedef TLockException LockException;

   virtual bool Lock() { return true; }
   virtual LockStatus TryLock() { return LockSuccess; }
   virtual LockStatus TimedLock(mseconds_t milliseconds) { return LockSuccess; }
   virtual LockStatus UntimedLock() { return LockSuccess; }
   virtual bool Unlock() { return true; }
};
typedef UnlockedT<> Unlocked;

typedef ImplementBase LockTImplements;
typedef Base LockTExtends;
//
// Class: LockT
//
template
<class TLocked = Locked,
 class TLockException = LockException,
 class TImplements = LockTImplements,
 class TExtends = LockTExtends>

class  LockT: virtual public TImplements, public TExtends {
public:
   typedef TImplements Implements;
   typedef TExtends Extends;

   typedef TLocked Locked;
   typedef TLockException LockException;

   LockT(Locked& locked): _locked(locked) {
      if (!(_locked.lock())) {
         LockException e(LockFailed);
         throw (e);
      }
   }
   virtual ~LockT() {
      if (!(_locked.unlock())) {
         LockException e(UnlockFailed);
         throw (e);
      }
   }
protected:
   Locked& _locked;
};
typedef LockT<> Lock;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
} // namespace universe 

#endif // _UNIVERSE_BASE_BASE_H
