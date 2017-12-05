%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath%)%)%)%,%
%methods,%(%else-then(%methods%,%(%include(%includepath%/http-methods.t)%)%)%)%,%
%%(%
%//
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
//   File: WebSignals.h
//
// Author: $author$
//   Date: %date()%
//
// Copyright (c) %year()% $organization$
//
#ifndef _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSIGNALS_H
#define _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSIGNALS_H

#include "universe/logger/Interface.h"
#include "libnavajo/libnavajo.hh"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

//
// Class: WebSignals
//
class WebSignals
{
public:%
%%parse(%methods%,%(, )%,,,,%(%
%%with(%
%METHOD,%(%else(%toupper%,%(%method%)%,%(%toupper(%method%)%)%)%)%,%
%method,%(%else(%tolower%,%(%method%)%,%(%tolower(%method%)%)%)%)%,%
%%(
   //
   // %METHOD%
   //
   virtual bool process_%METHOD%_Request(HttpRequest* request, HttpResponse *response) {
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_%METHOD%_Request(request, response)...");
         return forwardTo->process_%METHOD%_Request(request, response);
      }
      LOG_DEBUG("process_%METHOD%_Request(request, response)...");
      return false;
   })%)%%
%)%,method)%
   virtual bool processRequest(HttpRequest* request, HttpResponse *response) {
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->processRequest(request, response)...");
         return forwardTo->processRequest(request, response);
      }
      LOG_DEBUG("processRequest(request, response)...");
      return false;
   }
   virtual WebSignals* forwardSignalsTo(WebSignals* to) {
      return 0;
   }
   virtual WebSignals* signalsForwardTo() const {
      return 0;
   }
};

} // namespace libnavajo 
} // namespace daemon 
} // namespace http 
} // namespace protocol 
} // namespace universe 

#endif // _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSIGNALS_H
%
%)%)%