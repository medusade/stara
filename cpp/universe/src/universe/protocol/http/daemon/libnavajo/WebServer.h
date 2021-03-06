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
//   File: WebServer.h
//
// Author: $author$
//   Date: 12/3/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSERVER_H
#define _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSERVER_H

#include "universe/protocol/http/daemon/libnavajo/WebRepository.h"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

typedef WebRepository WebServerImplements;
typedef ::libnavajo::WebServer WebServerExtends;
//
// Class: WebServer
//
class WebServer
: virtual public WebServerImplements, public WebServerExtends {
public:
   typedef WebServerImplements Implements;
   typedef WebServerExtends Extends;

   WebServer() {
   }
   virtual ~WebServer() {
   }
};

typedef WebServerImplements ForwardedWebServerImplements;
typedef WebServer ForwardedWebServerExtends;
//
// Class: ForwardedWebServer
//
class ForwardedWebServer
: virtual public ForwardedWebServerImplements, public ForwardedWebServerExtends {
public:
   typedef ForwardedWebServerImplements Implements;
   typedef ForwardedWebServerExtends Extends;

   ForwardedWebServer
   (WebRepository* requestsForwardTo, WebSignals* signalsForwardTo)
   : _requestsForwardTo(requestsForwardTo), 
     _signalsForwardTo(signalsForwardTo) {
   }
   ForwardedWebServer(WebRepository* requestsForwardTo)
   : _requestsForwardTo(requestsForwardTo), _signalsForwardTo(0) {
   }
   ForwardedWebServer(WebSignals* signalsForwardTo)
   : _requestsForwardTo(0), _signalsForwardTo(signalsForwardTo) {
   }
   ForwardedWebServer()
   : _requestsForwardTo(0), _signalsForwardTo(0) {
   }
   virtual ~ForwardedWebServer() {
   }
private:
   ForwardedWebServer(const ForwardedWebServer& copy)
   : _requestsForwardTo(0), _signalsForwardTo(0) {
   }

public:
   static ForwardedWebServer* createInstance
   (WebRepository* requestsForwardTo, WebSignals* signalsForwardTo) {
      ForwardedWebServer* wr = new ForwardedWebServer(requestsForwardTo, signalsForwardTo);
      return wr;
   }
   static ForwardedWebServer* createInstance
   (WebRepository* requestsForwardTo) {
      ForwardedWebServer* wr = new ForwardedWebServer(requestsForwardTo);
      return wr;
   }
   static ForwardedWebServer* createInstance
   (WebSignals* signalsForwardTo) {
      ForwardedWebServer* wr = new ForwardedWebServer(signalsForwardTo);
      return wr;
   }
   static ForwardedWebServer* createInstance() {
      ForwardedWebServer* wr = new ForwardedWebServer();
      return wr;
   }

   virtual ForwardedWebRepository* createRepositoryForwardTo(WebRepository* to) {
      ForwardedWebRepository* wr = 0;
      if ((wr = ForwardedWebRepository::createInstance())) {
         wr->forwardRequestsTo(to);
         wr->forwardSignalsTo(to);
      }
      return wr;
   }
   virtual WebRepository* forwardRequestsTo(WebRepository* to) {
      WebRepository* forwardedTo = _requestsForwardTo;
      _requestsForwardTo = to;
      return forwardedTo;
   }
   virtual WebRepository* requestsForwardTo() const {
      return _requestsForwardTo;
   }
   
   virtual WebSignals* forwardSignalsTo(WebSignals* to) {
      WebSignals* forwardedTo = _signalsForwardTo;
      _signalsForwardTo = to;
      return forwardedTo;
   }
   virtual WebSignals* signalsForwardTo() const {
      return _signalsForwardTo;
   }

protected:
   virtual bool processRequest(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->processRequest(request, response)...");
         success = forwardTo->processRequest(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->processRequest(request, response)");
      }
      if (!(success) && (request)) {
         switch (request->getRequestType()) {
         case GET_METHOD: 
            success = process_GET_Request(request, response);
            break;
         case PUT_METHOD: 
            success = process_PUT_Request(request, response);
            break;
         case POST_METHOD: 
            success = process_POST_Request(request, response);
            break;
         case DELETE_METHOD: 
            success = process_DELETE_Request(request, response);
            break;
         case UPDATE_METHOD: 
            success = process_UPDATE_Request(request, response);
            break;
         case PATCH_METHOD: 
            success = process_PATCH_Request(request, response);
            break;
         case TRACE_METHOD: 
            success = process_OPTIONS_Request(request, response);
            break;
         case CONNECT_METHOD: 
            success = process_OPTIONS_Request(request, response);
            break;
         case OPTIONS_METHOD: 
            success = process_OPTIONS_Request(request, response);
            break;
         case HEAD_METHOD: 
            success = process_HEAD_Request(request, response);
            break;
         default:
            success = process_UNKNOWN_Request(request, response);
            break;
         }
      }
      return success;
   }
   virtual bool getFile(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebRepository* forwardTo = requestsForwardTo();
      if ((forwardTo)) {
         success = forwardTo->getFile(request, response);
      }
      if (!(success)) {
         success = processRequest(request, response);
      }
      return success;
   }

protected:
   WebRepository* _requestsForwardTo;
   WebSignals* _signalsForwardTo;
};

} // namespace libnavajo 
} // namespace daemon 
} // namespace http 
} // namespace protocol 
} // namespace universe 

#endif // _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSERVER_H
