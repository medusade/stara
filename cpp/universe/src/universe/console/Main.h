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
//   File: Main.h
//
// Author: $author$
//   Date: 12/2/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_CONSOLE_MAIN_H
#define _UNIVERSE_CONSOLE_MAIN_H

#include "universe/base/Base.h"
#include <getopt.h>

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
 class TImplements = ImplementBase>

class IoT
: virtual public TImplements
{
public:
   typedef TImplements Implements;

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

protected:
   virtual ssize_t outfv(file_t f, const char_t* format, va_list va) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile)) && (format)) {
           /*count = vfprint(f, format, va);*/
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
               if (0 < (amount /*= fwrite(out, sizeof(char_t), length, f)*/))
                   count += amount;
           } else {
               for (; *out; ++out) {
                   if (0 < (amount /*= fwrite(out, sizeof(char_t), 1, f)*/)) {
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
           if ((err /*= fflush(f)*/)) {
               count = -1;
           }
       }
       return count;
   }

   virtual ssize_t infv(file_t f, const char_t* format, va_list va) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile)) && (format)) {
           /*count = vfscanf(f, format, va);*/
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
           if (0 < (amount /*= fread(in, sizeof(char_t), size, f)*/)) {
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
       return ((file_t)nullFile)/*stdout*/;
   }
   virtual file_t stdErr() const {
       return ((file_t)nullFile)/*stderr*/;
   }
   virtual file_t stdIn() const {
       return ((file_t)nullFile)/*stdin*/;
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

protected:
   virtual ssize_t outfv(file_t f, const char_t* format, va_list va) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile)) && (format)) {
           count = vfprintf(f, format, va);
       }
       return count;
   }
   virtual ssize_t out(file_t f, const char_t* out, ssize_t length = -1) {
       ssize_t count = 0;
       if ((out) && (f != ((file_t)nullFile))) {
           ssize_t amount = 0;
           if (0 <= (length)) {
               if (0 < (amount = fwrite(out, sizeof(char_t), length, f)))
                   count += amount;
           } else {
               for (; *out; ++out) {
                   if (0 < (amount = fwrite(out, sizeof(char_t), 1, f))) {
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
           if ((err = fflush(f))) {
               count = -1;
           }
       }
       return count;
   }

   virtual ssize_t infv(file_t f, const char_t* format, va_list va) {
       ssize_t count = 0;
       if ((f != ((file_t)nullFile)) && (format)) {
           count = vfscanf(f, format, va);
       }
       return count;
   }
   virtual ssize_t in(file_t f, char_t* in, size_t size) {
       ssize_t count = 0;
       if ((in) && (f != ((file_t)nullFile)) && (0 < (size))) {
           ssize_t amount = 0;
           if (0 < (amount = fread(in, sizeof(char_t), size, f))) {
               count += amount;
           }
       }
       return count;
   }

   virtual file_t stdOut() const {
       return stdout;
   }
   virtual file_t stdErr() const {
       return stderr;
   }
   virtual file_t stdIn() const {
       return stdin;
   }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: MainT
//
template 
<typename TChar = char, class TIo = IoT<TChar>, 
 class TImplements = TIo, class TExtends = Base>

class MainT
: virtual public TImplements, public TExtends
{
public:
   typedef TImplements Implements;
   typedef TExtends Extends;

   typedef TChar char_t;
   typedef StringT<char_t> string_t;

   MainT()
   {
      MainT*& main = MainT::main();
      if (!(main)) {
         main = this;
      } else {
      }
   }
   virtual ~MainT()
   {
      MainT*& main = MainT::main();
      if ((main) && (this == main)) {
         main = 0;
      } else {
         if ((main)) {
         } else {
         }
      }
   }
private:
   MainT(const MainT& copy)
   {
   }

protected:
   virtual int run(int argc, char_t** argv, char_t** env) {
      int err = 0;
      return err;
   }
   virtual int beforeRun(int argc, char_t** argv, char_t** env) {
      int err = 0;
      return err;
   }
   virtual int afterRun(int argc, char_t** argv, char_t** env) {
      int err = 0;
      return err;
   }
   
   virtual int operator() (int argc, char_t** argv, char_t** env) {
      int err = 0, err2 = 0;
      if (!(err = beforeRun(argc, argv, env))) {
         err = run(argc, argv, env);
         if ((err2 = afterRun(argc, argv, env))) {
            if (!err) err = err2;
         }
      }
      return err;
   }

public:
   static int main(int argc, char_t** argv, char_t** env) {
      MainT* main = 0;
      if ((main = MainT::main())) {
         int err = (*main)(argc, argv, env);
         return err;
      }
      return 1;
   }

protected:
   static MainT*& main() {
      static MainT* main = 0;
      return main;
   }
};
typedef Io MainImplement;
typedef MainT<char, Io> MainExtend;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Enum: MAIN_OPT_ARGUMENT_T
//
typedef int MAIN_OPT_ARGUMENT_T;
enum {
    MAIN_OPT_ARGUMENT_NONE     = 0,
    MAIN_OPT_ARGUMENT_REQUIRED = 1,
    MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

#define MAIN_USAGE_OPT "usage"
#define MAIN_USAGE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MAIN_USAGE_OPTARG_RESULT 0
#define MAIN_USAGE_OPTARG ""
#define MAIN_USAGE_OPTUSE "Usage"
#define MAIN_USAGE_OPTVAL_S "?"
#define MAIN_USAGE_OPTVAL_C '?'
#define MAIN_USAGE_OPTION \
   {MAIN_USAGE_OPT, \
    MAIN_USAGE_OPTARG_REQUIRED, \
    MAIN_USAGE_OPTARG_RESULT, \
    MAIN_USAGE_OPTVAL_C}, \

#define MAIN_OPTIONS_CHARS \
   MAIN_USAGE_OPTVAL_S \

#define MAIN_OPTIONS_OPTIONS \
   MAIN_USAGE_OPTION \

#define MAIN_ARGS 0
#define MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: MainOpt
//
class MainOpt
: virtual public ImplementBase
{
public:
   typedef ImplementBase Implements;

protected:
   virtual int usage(int argc, char** argv, char** env) {
       int err = 0;
       return err;
   }
   
   virtual int getOptions(int argc, char** argv, char** env) {
       int err = 0;
       int longindex = 0;
       const struct option* longopts = 0;
       char optvaluename[2] = {0,0};
       const char* optname = optvaluename;
       const char* optstring = 0;
       int optvalue = 0;

       if ((optstring = this->options(longopts)) && (longopts)) {
           while (0 <= (optvalue = getopt_long(argc, argv, optstring, longopts, &longindex))) {
               optvaluename[0] = optvalue;
               optname = (longindex)?(longopts[longindex].name):(optvaluename);

               if ((err = this->onOption(optvalue, optarg, optname, longindex, argc, argv, env))) {
                   break;
               }
           }
       }
       if (!(err)) {
          if (argc > (optind)) {
              for (int argind = optind; argind < argc; ++argind) {
                  if ((err = this->onArgument(argv[argind], argind-optind, argc, argv, env))) {
                      break;
                  }
              }
          }
       }
       return err;
   }
   virtual int beforeGetOptions(int argc, char** argv, char** env) {
       int err = 0;
       return err;
   }
   virtual int afterGetOptions(int argc, char** argv, char** env) {
       int err = 0;
       return err;
   }

   virtual int onUsageOption
   (int optval, const char_t* optarg,
    const char_t* optname, int optind,
    int argc, char_t**argv, char_t**env) {
       int err = 0;
       usage(argc, argv, env);
       return err;
   }
   virtual int onOption
   (int optval, const char_t* optarg,
    const char_t* optname, int optind,
    int argc, char_t**argv, char_t**env) {
       int err = 0;
       switch(optval) {
       case MAIN_USAGE_OPTVAL_C:
           err = onUsageOption
           (optval, optarg, optname, optind, argc, argv, env);
           break;
       default:
           err = onInvalidOption
           (optval, optarg, optname, optind, argc, argv, env);
       }
       return err;
   }
   virtual int onInvalidOption
   (int optval, const char_t* optarg,
    const char_t* optname, int optind,
    int argc, char_t**argv, char_t**env) {
       int err = 0;
       if ((optarg) && (optarg[0])) {
       }
       return err;
   }

   virtual const char_t* optionUsage
   (const char_t*& optarg, const struct option* longopt) {
       const char_t* chars = "";
       switch(longopt->val) {
       case MAIN_USAGE_OPTVAL_C:
           optarg = MAIN_USAGE_OPTARG;
           chars = MAIN_USAGE_OPTUSE;
           break;
       default:
           chars = invalidOptionUsage(optarg, longopt);
       }
       return chars;
   }
   virtual const char_t* invalidOptionUsage
   (const char_t*& optarg, const struct option* longopt) {
       const char_t* chars = "";
       return chars;
   }

   virtual const char_t* options(const struct option*& longopts) {
       int err = 0;
       static const char_t* chars = MAIN_OPTIONS_CHARS;
       static struct option optstruct[]= {
           MAIN_OPTIONS_OPTIONS
           {0, 0, 0, 0}};
       longopts = optstruct;
       return chars;
   }

   virtual int onArgument
   (const char_t* arg, int argind,
    int argc, char_t** argv, char_t** env) {
       int err = 0;
       return err;
   }
   virtual int missingArgument
   (const char_t* arg, int argind,
    int argc, char_t** argv, char_t** env) {
       int err = 0;
       return err;
   }
   virtual const char_t* arguments(const char_t**& argv) {
       static const char_t* _args = MAIN_ARGS;
       static const char_t* _argv[] = {
           MAIN_ARGV
           0};
       argv = _argv;
       return _args;
   }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Class: Main
//
class Main
: virtual public MainOpt, virtual public MainImplement, public MainExtend
{
public:
   typedef MainOpt OptImplements;
   typedef MainImplement Implements;
   typedef MainExtend Extends;

   Main(): _didUsage(false)
   {
   }
   virtual ~Main()
   {
   }
private:
   Main(const Main& copy)
   {
   }

protected:
   virtual int run(int argc, char_t** argv, char_t** env) {
      int err = 0;
      err = this->usage(argc, argv, env);
      return err;
   }
   virtual int beforeRun(int argc, char_t** argv, char_t** env) {
      int err = 0, err2 = 0;
      if (!(err = this->beforeGetOptions(argc, argv, env))) {
         err = this->getOptions(argc, argv, env);
         if ((err2 = this->afterGetOptions(argc, argv, env))) {
            if (!err) err = err2;
         }
      }
      return err;
   }
   
   virtual int usage(int argc, char** argv, char** env) {
       int err = 0;

       if (!(didUsage())) {
           const char* arg = 0;
           const char** args = 0;
           const char* argstring = arguments(args);
           const struct option* longopts = 0;
           const char* optstring = options(longopts);
           const char* name = usageName(argc, argv, env);

           outf
           ("Usage: %s%s%s%s\n", (name)?(name):(""),
            (optstring)?(" [options]"):(""),
            (argstring)?(" "):(""), (argstring)?(argstring):(""));

           if ((optstring) && (longopts)) {
               outf("\nOptions:\n");

               while ((longopts->name)) {
                   const char* optarg =
                   (MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                   ((MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                   const char* optusage = optionUsage(optarg, longopts);
                   const char* optargSeparator = (optarg[0])?(" "):("");
                   const char* optusageSeparator = "  ";

                   outf
                   (" -%c --%s%s%s%s%s\n",
                    longopts->val, longopts->name,
                    optargSeparator, optarg, optusageSeparator, optusage);
                   longopts++;
               }
           }

           if ((argstring) && (args)) {
               outf("\nArguments:\n");

               while ((arg = (*args))) {
                   outf(" %s\n", arg);
                   args++;
               }
           }
           setDidUsage();
       }
       return err;
   }
   virtual const char* usageName
   (int argc, char_t** argv, char_t** env) const {
       const char_t* arg0 = (0 < argc)?((argv)?(argv[0]):(0)):(0);
       if ((arg0)) {
           for (const char_t* i = arg0; *i; ++i) {
               char c = (char)(*i);
               if (('/' == c) || ('\\' == c) || (':' == c)) {
                   arg0 = i + 1;
               }
           }
       }
       return arg0;
   }

   virtual bool setDidUsage(bool to = true) {
      _didUsage = to;
      return _didUsage;
   }
   virtual bool didUsage() const {
      return _didUsage;
   }
   
protected:
   bool _didUsage;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
} // namespace console 
} // namespace universe 

#endif // _UNIVERSE_CONSOLE_MAIN_H
