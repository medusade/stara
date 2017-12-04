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
typedef ::WebServer WebServerExtends;
//
// Class: WebServer
//
class WebServer
: virtual public WebServerImplements, public WebServerExtends
{
public:
   typedef WebServerImplements Implements;
   typedef WebServerExtends Extends;

   WebServer()
   {
   }
   virtual ~WebServer()
   {
   }
private:
   WebServer(const WebServer& copy)
   {
   }

public:
   virtual WebRepository* newWebRepositoryForwardTo(WebRepository* to) {
      ForwardedWebRepository* wr = 0;
      if ((wr = new ForwardedWebRepository)) {
         wr->forwardRequestsTo(to);
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

protected:
   WebRepository* _requestsForwardTo;
};

} // namespace libnavajo 
} // namespace daemon 
} // namespace http 
} // namespace protocol 
} // namespace universe 

#endif // _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSERVER_H
