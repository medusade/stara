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

#include "universe/base/Base.h"
#include "libnavajo/libnavajo.hh"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

typedef ::WebRepository WebRepositoryImplements;
//
// Class: WebRepository
//
class WebRepository
: virtual public WebRepositoryImplements
{
public:
   typedef WebRepositoryImplements Implements;

   virtual bool getFile(HttpRequest* request, HttpResponse *response) {
      WebRepository* forwardTo = requestsForwardTo();
      if ((forwardTo)) {
         return forwardTo->getFile(request, response);
      }
      return false;
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
: virtual public ForwardedWebRepositoryImplements
{
public:
   typedef ForwardedWebRepositoryImplements Implements;

   ForwardedWebRepository(): _requestsForwardTo(0)
   {
   }
   virtual ~ForwardedWebRepository()
   {
   }
private:
   ForwardedWebRepository(const ForwardedWebRepository& copy)
   {
   }

public:
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

#endif // _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBREPOSITORY_H
