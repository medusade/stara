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
//   File: WebRepository.h
//
// Author: $author$
//   Date: 12/3/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBREPOSITORY_H
#define _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBREPOSITORY_H

#include "universe/protocol/http/daemon/libnavajo/WebSignals.h"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

typedef ::libnavajo::WebRepository WebRepositoryImplements;
typedef WebSignals WebSignalsImplements;
//
// Class: WebRepository
//
class WebRepository
: virtual public WebRepositoryImplements, virtual public WebSignalsImplements {
public:
   typedef WebRepositoryImplements RepositoryImplements;
   typedef WebSignalsImplements SignalsImplements;

   virtual bool getFile(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebRepository* forwardTo = requestsForwardTo();
      if ((forwardTo)) {
         success = forwardTo->getFile(request, response);
      }
      return success;
   }
   virtual void freeFile(unsigned char *webpage) {
      WebRepository* forwardTo = requestsForwardTo();
      if ((forwardTo)) {
         forwardTo->freeFile(webpage);
      } else {
         if ((webpage)) {
            ::free(webpage);
         }
      }
   }
   
   virtual WebRepository* forwardRequestsTo(WebRepository* to) {
      return 0;
   }
   virtual WebRepository* requestsForwardTo() const {
      return 0;
   }
};

typedef WebRepository ForwardedWebRepositoryImplements;
//
// Class: ForwardedWebRepository
//
class ForwardedWebRepository
: virtual public ForwardedWebRepositoryImplements {
public:
   typedef ForwardedWebRepositoryImplements Implements;

   ForwardedWebRepository
   (WebRepository* requestsForwardTo, WebSignals* signalsForwardTo)
   : _requestsForwardTo(requestsForwardTo), 
     _signalsForwardTo(signalsForwardTo) {
   }
   ForwardedWebRepository(WebRepository* requestsForwardTo)
   : _requestsForwardTo(requestsForwardTo), _signalsForwardTo(0) {
   }
   ForwardedWebRepository(WebSignals* signalsForwardTo)
   : _requestsForwardTo(0), _signalsForwardTo(signalsForwardTo) {
   }
   ForwardedWebRepository()
   : _requestsForwardTo(0), _signalsForwardTo(0) {
   }
   virtual ~ForwardedWebRepository() {
   }
private:
   ForwardedWebRepository(const ForwardedWebRepository& copy)
   : _requestsForwardTo(0), _signalsForwardTo(0) {
   }

public:
   static ForwardedWebRepository* createInstance
   (WebRepository* requestsForwardTo, WebSignals* signalsForwardTo) {
      ForwardedWebRepository* wr = new ForwardedWebRepository(requestsForwardTo, signalsForwardTo);
      return wr;
   }
   static ForwardedWebRepository* createInstance
   (WebRepository* requestsForwardTo) {
      ForwardedWebRepository* wr = new ForwardedWebRepository(requestsForwardTo);
      return wr;
   }
   static ForwardedWebRepository* createInstance
   (WebSignals* signalsForwardTo) {
      ForwardedWebRepository* wr = new ForwardedWebRepository(signalsForwardTo);
      return wr;
   }
   static ForwardedWebRepository* createInstance() {
      ForwardedWebRepository* wr = new ForwardedWebRepository();
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
   WebRepository* _requestsForwardTo;
   WebSignals* _signalsForwardTo;
};

} // namespace libnavajo 
} // namespace daemon 
} // namespace http 
} // namespace protocol 
} // namespace universe 

#endif // _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBREPOSITORY_H
