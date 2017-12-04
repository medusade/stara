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

#include "universe/console/Logger.h"
#include "universe/console/Io.h"
#include <getopt.h>

namespace universe {
namespace console {

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

   MainT(): _didRun(false)
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
         if (!(didRun())) {
            err = run(argc, argv, env);
         }
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
   
   virtual bool setDidRun(bool to = true) {
      _didRun = to;
      return _didRun;
   }
   virtual bool didRun() const {
      return _didRun;
   }

protected:
   bool _didRun;
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
      if ((_didUsage = to)) {
         this->setDidRun();
      }
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
