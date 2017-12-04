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
//   File: Output.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_LOGGER_OUTPUT_H
#define _UNIVERSE_LOGGER_OUTPUT_H

#include "universe/logger/Enabled.h"
#include "universe/logger/Stdio.h"

namespace universe {
namespace logger {

typedef Enabled OutputImplements;
//
// Class: Output
//
class _EXPORT_CLASS Output: virtual public OutputImplements {
public:
    typedef OutputImplements Implements;
protected:
    virtual void log(const Location& _location) {
        log(_location.fileName().c_str());
        log("[");
        log(_location.lineNumber().c_str());
        log("]");
        log(" ");
        log(_location.functionName().c_str());
        log(": ");
    }
    virtual void log(const Function& _function) {
        log(_function.c_str());
        log(": ");
    }
    virtual void log(const Message& _message) {
        log(_message.c_str());
    }
    virtual void log(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (char c = *(chars); length; --length, c = *(++chars)) {
                ::std::cerr << c;
            }
        }
    }
    virtual void log(const char* chars) {
        ::std::cerr << chars;
    }
    virtual void logLn() {
        ::std::cerr << ::std::endl;
        ::std::cerr.flush();
    }
};

} // namespace logger 
} // namespace universe 

#endif // _UNIVERSE_LOGGER_OUTPUT_H
