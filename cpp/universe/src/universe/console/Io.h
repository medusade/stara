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
//   File: Io.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_CONSOLE_IO_H
#define _UNIVERSE_CONSOLE_IO_H

#include "universe/base/Base.h"

namespace universe {
namespace console {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: IoT
//
template 
<typename TChar = char, 
 typename TFile = FILE*,
 class TLocked = Locked,
 class TImplements = TLocked>

class IoT
: virtual public TImplements
{
public:
   typedef TImplements Implements;
   typedef IoT IoBase;

   typedef TFile file_t;
   typedef int null_file_t;
   enum { nullFile = 0 };

   typedef TChar char_t;
   typedef StringT<char_t> string_t;

   virtual ssize_t outf(const char_t* format, ...) {
       ssize_t count = 0;
       va_list va;
       if ((format)) {
           va_start(va, format);
           count = this->outfv(format, va);
           va_end(va);
       }
       return count;
   }
   virtual ssize_t outl(const char_t* out, ...) {
       ssize_t count = 0;
       va_list va;
       if ((out)) {
           va_start(va, out);
           count = outlv(out, va);
           va_end(va);
       }
       return count;
   }
   virtual ssize_t outlnl(const char_t* out, ...) {
       ssize_t count = 0, amount = 0;
       va_list va;
       if ((out)) {
           va_start(va, out);
           count = this->outlv(out, va);
           va_end(va);
       }
       if (0 <= (count)) {
           if (0 <= (amount = this->outln())) {
               count += amount;
           } else {
               count = amount;
           }
       }
       return count;
   }

   virtual ssize_t errf(const char_t* format, ...) {
       ssize_t count = 0;
       va_list va;
       if ((format)) {
           va_start(va, format);
           count = this->errfv(format, va);
           va_end(va);
       }
       return count;
   }
   virtual ssize_t errl(const char_t* out, ...) {
       ssize_t count = 0;
       va_list va;
       if ((out)) {
           va_start(va, out);
           count = this->errlv(out, va);
           va_end(va);
       }
       return count;
   }
   virtual ssize_t errlnl(const char_t* out, ...) {
       ssize_t count = 0, amount = 0;
       va_list va;
       if ((out)) {
           va_start(va, out);
           count = this->errlv(out, va);
           va_end(va);
       }
       if (0 <= (count)) {
           if (0 <= (amount = this->errln())) {
               count += amount;
           } else {
               count = amount;
           }
       }
       return count;
   }

   virtual ssize_t inf(const char_t* format, ...) {
       ssize_t count = 0;
       va_list va;
       if ((format)) {
           va_start(va, format);
           count = infv(format, va);
           va_end(va);
       }
       return count;
   }

   virtual ssize_t outfv(const char_t* format, va_list va) {
       ssize_t count = outfv(this->outStdOut(), format, va);
       return count;
   }
   virtual ssize_t outlv(const char_t* out, va_list va) {
       ssize_t count = this->outlv(this->outStdOut(), out, va);
       return count;
   }
   virtual ssize_t outln(const char_t* out, ssize_t length = -1) {
       ssize_t count = this->outln(this->outStdOut(), out, length);
       return count;
   }
   virtual ssize_t outln() {
       ssize_t count = this->outln(this->outStdOut());
       return count;
   }
   virtual ssize_t out(const char_t* out, ssize_t length = -1) {
       ssize_t count = this->out(this->outStdOut(), out, length);
       return count;
   }
   virtual ssize_t outFlush() {
       ssize_t count = this->outFlush(this->outStdOut());
       return count;
   }

   virtual ssize_t errfv(const char_t* format, va_list va) {
       ssize_t count = outfv(this->outStdErr(), format, va);
       return count;
   }
   virtual ssize_t errlv(const char_t* out, va_list va) {
       ssize_t count = this->outlv(this->outStdErr(), out, va);
       return count;
   }
   virtual ssize_t errln(const char_t* out, ssize_t length = -1) {
       ssize_t count = this->outln(this->outStdErr(), out, length);
       return count;
   }
   virtual ssize_t errln() {
       ssize_t count = this->outln(this->outStdErr());
       return count;
   }
   virtual ssize_t err(const char_t* out, ssize_t length = -1) {
       ssize_t count = this->out(this->outStdErr(), out, length);
       return count;
   }
   virtual ssize_t errFlush() {
       ssize_t count = this->outFlush(this->outStdErr());
       return count;
   }

   virtual ssize_t infv(const char_t* format, va_list va) {
       ssize_t count = this->infv(this->inStdIn(), format, va);
       return count;
   }
   virtual ssize_t inln(char_t* in, size_t size) {
       ssize_t count = this->inln(this->inStdIn(), in, size);
       return count;
   }
   virtual ssize_t in(char_t* in, size_t size) {
       ssize_t count = this->in(this->inStdIn(), in, size);
       return count;
   }
   virtual ssize_t inFill() {
       ssize_t count = this->inFill(this->inStdIn());
       return count;
   }

   virtual bool lock() {
      IoT* io = IoT::theIo();
      if ((io)) {
         return io->lock();
      }
      return true; 
   }
   virtual LockStatus tryLock() { 
      IoT* io = IoT::theIo();
      if ((io)) {
         return io->tryLock();
      }
      return LockSuccess; 
   }
   virtual LockStatus timedLock(mseconds_t milliseconds) { 
      IoT* io = IoT::theIo();
      if ((io)) {
         return io->timedLock(milliseconds);
      }
      return LockSuccess; 
   }
   virtual LockStatus untimedLock() { 
      IoT* io = IoT::theIo();
      if ((io)) {
         return io->untimedLock();
      }
      return LockSuccess; 
   }
   virtual bool unlock() { 
      IoT* io = IoT::theIo();
      if ((io)) {
         return io->unlock();         
      }
      return true; 
   }

   static IoT* setTheIo(IoT* to) {
      IoT *&ioSet = theIoSet(), *oldIo = ioSet;
      ioSet = to;
      return oldIo;
   }
   static IoT* theIo() {
      IoT* io = theIoSet();
      return io;
   }
protected:
   static IoT*& theIoSet() {
      static IoT* theIo = 0;
      return theIo;
   }
   
   virtual ssize_t outfv(file_t f, const char_t* format, va_list va) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile)) && (format)) {
           count = this->vfPrintf(f, format, va);
       }
       return count;
   }
   virtual ssize_t outlv(file_t f, const char_t* out, va_list va) {
       ssize_t count = 0;
       ssize_t amount = 0;
       for (count = 0; out; count += amount) {
           if (0 > (amount = this->out(f, out))) {
               return amount;
           }
           out = va_arg(va, const char_t*);
       }
       return count;
   }
   virtual ssize_t outln(file_t f, const char_t* out, ssize_t length = -1) {
       ssize_t count = 0;
       ssize_t amount;
       if (0 <= (amount = this->out(f, out, length))) {
           count += amount;
           if (0 <= (amount = this->outln(f))) {
               count += amount;
           }
       }
       return count;
   }
   virtual ssize_t outln(file_t f) {
       const char_t ln = ((char_t)'\n');
       ssize_t count = out(f, &ln, 1);
       return count;
   }
   virtual ssize_t out(file_t f, const char_t* out, ssize_t length = -1) {
       ssize_t count = 0;
       if ((out) && (f != ((file_t)nullFile))) {
           ssize_t amount = 0;
           if (0 <= (length)) {
               if (0 < (amount = this->fWrite(out, sizeof(char_t), length, f)))
                   count += amount;
           } else {
               for (; *out; ++out) {
                   if (0 < (amount = this->fWrite(out, sizeof(char_t), 1, f))) {
                       count += amount;
                       continue;
                   }
                   break;
               }
           }
       }
       return count;
   }
   virtual ssize_t outFlush(file_t f) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile))) {
           int err = 0;
           if ((err = this->fFlush(f))) {
               count = -1;
           }
       }
       return count;
   }

   virtual ssize_t infv(file_t f, const char_t* format, va_list va) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile)) && (format)) {
           count = this->vfScanf(f, format, va);
       }
       return count;
   }
   virtual ssize_t inln(file_t f, char_t* in, size_t size) {
       ssize_t count = 0;
       if ((in) && (f != ((file_t)nullFile)) && (0 < (size))) {
           const char_t ln = ((char_t)'\n');
           char_t c;
           ssize_t amount;
           while (0 < (size)) {
               if (0 > (amount = this->in(f, &c, 1))) {
                   count = amount;
               } else {
                   --size;
                   if (ln != c) {
                       *in = c;
                       ++in;
                       continue;
                   }
               }
               break;
           }
       }
       return count;
   }
   virtual ssize_t in(file_t f, char_t* in, size_t size) {
       ssize_t count = 0;
       if ((in) && (f != ((file_t)nullFile)) && (0 < (size))) {
           ssize_t amount = 0;
           if (0 < (amount = this->fRead(in, sizeof(char_t), size, f))) {
               count += amount;
           }
       }
       return count;
   }
   virtual ssize_t inFill(file_t f) {
       ssize_t count = 0;
       return count;
   }

   virtual file_t outStdOut() {
       return this->stdOut();
   }
   virtual file_t outStdErr() {
       return this->stdErr();
   }
   virtual file_t inStdIn() {
       return this->stdIn();
   }

   virtual file_t stdOut() const {
       return ((file_t)nullFile)/*::stdout*/;
   }
   virtual file_t stdErr() const {
       return ((file_t)nullFile)/*::stderr*/;
   }
   virtual file_t stdIn() const {
       return ((file_t)nullFile)/*::stdin*/;
   }

   virtual ssize_t vfPrintf(file_t f, const char_t* format, va_list va) const {
       return -1/*::vfprintf(f, format, va)*/;
   }
   virtual ssize_t fWrite(const void* out, size_t size, size_t length, file_t f) const {
       return -1/*::fwrite(out, size, length, f)*/;
   }
   virtual int fFlush(file_t f) const {
      return -1/*::fflush(f)*/;
   }
   virtual ssize_t vfScanf(file_t f, const char_t* format, va_list va) const {
       return -1/*::vfscanf(f, format, va)*/;
   }
   virtual ssize_t fRead(void* in, size_t size, size_t count, file_t f) const {
       return -1/*::fread(in, sizeof(char_t), size, f)*/;
   }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

typedef IoT<char> IoImplements;
//
// Class: Io
//
class Io
: virtual public IoImplements
{
public:
   typedef IoImplements Implements;
   typedef typename Implements::IoBase IoBase;

protected:
   virtual file_t stdOut() const {
       return ::stdout;
   }
   virtual file_t stdErr() const {
       return ::stderr;
   }
   virtual file_t stdIn() const {
       return stdin;
   }
   virtual ssize_t vfPrintf(file_t f, const char_t* format, va_list va) const {
       return ::vfprintf(f, format, va);
   }
   virtual ssize_t fWrite(const void* out, size_t size, size_t length, file_t f) const {
       return ::fwrite(out, size, length, f);
   }
   virtual int fFlush(file_t f) const {
      return ::fflush(f);
   }
   virtual ssize_t vfScanf(file_t f, const char_t* format, va_list va) const {
       return ::vfscanf(f, format, va);
   }
   virtual ssize_t fRead(void* in, size_t size, size_t count, file_t f) const {
       return ::fread(in, sizeof(char_t), size, f);
   }
};

//
// Class: IoExtendT
//
template 
<typename TChar = char, class TIo = IoT<TChar>, 
 class TImplements = TIo, class TExtends = Base>

class IoExtendT
: virtual public TImplements, public TExtends
{
public:
   typedef TImplements Implements;
   typedef TExtends Extends;
   typedef typename Implements::IoBase IoBase;

   IoExtendT(Locked& locked): _locked(locked)
   {
   }
   IoExtendT(const IoExtendT& copy): _locked(_unlocked)
   {
   }
   IoExtendT(): _locked(_unlocked)
   {
   }
   virtual ~IoExtendT()
   {
   }
   
   virtual bool lock() { 
      return _locked.lock(); 
   }
   virtual LockStatus tryLock() { 
      return _locked.tryLock(); 
   }
   virtual LockStatus timedLock(mseconds_t milliseconds) { 
      return _locked.timedLock(milliseconds); 
   }
   virtual LockStatus untimedLock() { 
      return _locked.untimedLock(); 
   }
   virtual bool unlock() { 
      return _locked.unlock(); 
   }

protected:
   Unlocked _unlocked;
   Locked& _locked;
};
typedef IoExtendT<char, Io> IoExtend;

//
// Class: IoInstanceT
//
template 
<typename TChar = char, 
 class TIo = IoT<TChar>, 
 class TIoExtend = IoExtendT<TChar, TIo>, 
 class TImplements = TIo, class TExtends = TIoExtend>

class IoInstanceT
: virtual public TImplements, public TExtends
{
public:
   typedef TImplements Implements;
   typedef TExtends Extends;
   typedef typename Implements::IoBase IoBase;

   IoInstanceT(Locked& locked)
   : Extends(locked), _theIo(IoBase::theIo())
   {
      IoBase*& theIoSet = IoBase::theIoSet();
      theIoSet = this;
   }
   IoInstanceT(): _theIo(IoBase::theIo())
   {
      IoBase*& theIoSet = IoBase::theIoSet();
      theIoSet = this;
   }
   virtual ~IoInstanceT()
   {
      IoBase*& theIoSet = IoBase::theIoSet();
      if (this == (theIoSet)) {
         theIoSet = _theIo;
      }
   }
private:
   IoInstanceT(const IoInstanceT& copy)
   {
   }

protected:
   IoBase* _theIo;
};
typedef IoInstanceT<char, Io, IoExtend> IoInstance;

} // namespace console 
} // namespace universe 

#endif // _UNIVERSE_CONSOLE_IO_H
