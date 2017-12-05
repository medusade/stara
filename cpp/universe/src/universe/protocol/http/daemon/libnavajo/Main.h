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
//   Date: 12/3/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_MAIN_H
#define _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_MAIN_H

#include "universe/protocol/http/daemon/libnavajo/WebServer.h"
#include "universe/protocol/http/daemon/libnavajo/WebRepository.h"
#include "universe/console/Main.h"
#include "libnavajo/libnavajo.hh"
#include "libnavajo/LogStdOutput.hh"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

typedef console::Main::OptImplements MainOptImplements;
typedef console::Main::Implements MainImplements;
typedef console::Main MainExtends;
//
// Class: Main
//
class Main
: virtual public WebRepository, virtual public MainOptImplements, 
  virtual public MainImplements, public MainExtends
{
public:
   typedef OptImplements OptImplements;
   typedef MainImplements Implements;
   typedef MainExtends Extends;
   typedef Main Derives;

   Main(Locked& locked)
   : Extends(locked), _run(0), _port(8080)
   {
   }
   Main(): _run(0), _port(8080)
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
      if ((this->_run)) {
         err = (this->*_run)(argc, argv, env);
      } else {
         //err = this->usage(argc, argv, env);
         err = this->runStart(argc, argv, env);
      }
      return err;
   }
   virtual int runStart(int argc, char_t** argv, char_t** env) {
      int err = 0;
      try {
         WebServer*& ws = theWebServer();

         if ((ws = new WebServer)) {
            WebRepository* wr = 0;

            if ((wr = ws->newWebRepositoryForwardTo(ws))) {
               ws->forwardRequestsTo(this);
               ws->addRepository(wr);
               ws->setServerPort(port());
               ws->startService();
               ws->wait();
            } else {
            }
         } else {
         }
      } catch (...) {
         err = 1;
      }
      return err;
   }

   virtual bool processRequest(HttpRequest* request, HttpResponse *response) {
      LOG_DEBUG("-->processRequest(HttpRequest* request, HttpResponse *response)");
      LOG_DEBUG("<--processRequest(HttpRequest* request, HttpResponse *response)");
      return false;
   }
   virtual bool process_GET_Request(HttpRequest* request, HttpResponse *response) {
      LOG_DEBUG("-->process_GET_Request(HttpRequest* request, HttpResponse *response)");
      LOG_DEBUG("<--process_GETRequest(HttpRequest* request, HttpResponse *response)");
      return false;
   }
   virtual bool process_POST_Request(HttpRequest* request, HttpResponse *response) {
      LOG_DEBUG("-->process_POST_Request(HttpRequest* request, HttpResponse *response)");
      LOG_DEBUG("<--process_POSTRequest(HttpRequest* request, HttpResponse *response)");
      return false;
   }
   
   virtual ushort setPort(ushort to) {
      _port = to;
      return _port;
   }
   virtual ushort port() const {
      return _port;
   }
   
   typedef void (*Signal)(int signum);
   static void connectSignals() {
      Signal &sigtermConnected = theSigtermConnected(), &sigterm = theSigterm(), 
             &sigintConnected = theSigintConnected(), &sigint = theSigint();

      if (!(sigtermConnected)) {
         ERR_LOG_DEBUG("signal(SIGTERM = " << SIGTERM << ", onSignal)...");
         sigterm = signal(SIGTERM, sigtermConnected = onSignal);
      }

      if (!(sigintConnected)) {
         ERR_LOG_DEBUG("signal(SIGINT = " << SIGINT << ", onSignal)...");
         sigint = signal(SIGINT, sigintConnected = onSignal);
      }
   }
   static void disconnectSignals() {
      Signal &sigtermConnected = theSigtermConnected(), &sigterm = theSigterm(), 
             &sigintConnected = theSigintConnected(), &sigint = theSigint();

      if ((sigintConnected)) {
         ERR_LOG_DEBUG("signal(SIGINT = " << SIGINT << ", sigint)...");
         signal(SIGINT, sigint);
         sigintConnected = 0;
      }
      
      if ((sigtermConnected)) {
         ERR_LOG_DEBUG("signal(SIGTERM = " << SIGTERM << ", sigterm)...");
         signal(SIGTERM, sigterm);
         sigtermConnected = 0;
      }
   }
   static void onSignal(int signum) {
      WebServer* ws = theWebServer();
      ERR_LOG_DEBUG("...onSignal(int signum = " << signum << ")");
      if ((ws)) {
         ERR_LOG_DEBUG("ws->stopService()...");
         ws->stopService();
         ERR_LOG_DEBUG("...ws->stopService()");
      }
   }
   static Signal& theSigtermConnected() {
      static Signal s = 0;
      return s;
   }
   static Signal& theSigterm() {
      static Signal s = 0;
      return s;
   }
   static Signal& theSigintConnected() {
      static Signal s = 0;
      return s;
   }
   static Signal& theSigint() {
      static Signal s = 0;
      return s;
   }
   static WebServer*& theWebServer() {
      static WebServer* ws = 0;
      return ws;
   }

public:
   static int main(int argc, char_t** argv, char_t** env) {
      int err = 0;

      ERR_LOG_DEBUG("main.connectSignals()...");
      connectSignals();

      err = Extends::main(argc, argv, env);
      
      ERR_LOG_DEBUG("main.disconnectSignals()...");
      disconnectSignals();
      return err;
   }

protected:
   int (Derives::*_run)(int argc, char_t** argv, char_t** env);
   ushort _port;
};

} // namespace libnavajo 
} // namespace daemon 
} // namespace http 
} // namespace protocol 
} // namespace universe 


#endif // _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_MAIN_H
