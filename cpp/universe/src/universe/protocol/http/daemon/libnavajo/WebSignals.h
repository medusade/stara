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
//   File: WebSignals.h
//
// Author: $author$
//   Date: 12/6/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSIGNALS_H
#define _UNIVERSE_PROTOCOL_HTTP_DAEMON_LIBNAVAJO_WEBSIGNALS_H

#include "universe/protocol/http/daemon/libnavajo/libnavajo.h"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

//
// Class: WebSignals
//
class WebSignals {
public:
   //
   // GET
   //
   virtual bool process_GET_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_GET_Request(request, response)...");
         success = forwardTo->process_GET_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_GET_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_GET_Request(request, response)");
      }
      return success;
   }
   //
   // POST
   //
   virtual bool process_POST_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_POST_Request(request, response)...");
         success = forwardTo->process_POST_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_POST_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_POST_Request(request, response)");
      }
      return success;
   }
   //
   // PUT
   //
   virtual bool process_PUT_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_PUT_Request(request, response)...");
         success = forwardTo->process_PUT_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_PUT_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_PUT_Request(request, response)");
      }
      return success;
   }
   //
   // DELETE
   //
   virtual bool process_DELETE_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_DELETE_Request(request, response)...");
         success = forwardTo->process_DELETE_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_DELETE_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_DELETE_Request(request, response)");
      }
      return success;
   }
   //
   // UPDATE
   //
   virtual bool process_UPDATE_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_UPDATE_Request(request, response)...");
         success = forwardTo->process_UPDATE_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_UPDATE_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_UPDATE_Request(request, response)");
      }
      return success;
   }
   //
   // PATCH
   //
   virtual bool process_PATCH_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_PATCH_Request(request, response)...");
         success = forwardTo->process_PATCH_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_PATCH_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_PATCH_Request(request, response)");
      }
      return success;
   }
   //
   // TRACE
   //
   virtual bool process_TRACE_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_TRACE_Request(request, response)...");
         success = forwardTo->process_TRACE_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_TRACE_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_TRACE_Request(request, response)");
      }
      return success;
   }
   //
   // CONNECT
   //
   virtual bool process_CONNECT_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_CONNECT_Request(request, response)...");
         success = forwardTo->process_CONNECT_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_CONNECT_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_CONNECT_Request(request, response)");
      }
      return success;
   }
   //
   // OPTIONS
   //
   virtual bool process_OPTIONS_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_OPTIONS_Request(request, response)...");
         success = forwardTo->process_OPTIONS_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_OPTIONS_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_OPTIONS_Request(request, response)");
      }
      return success;
   }
   //
   // HEAD
   //
   virtual bool process_HEAD_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_HEAD_Request(request, response)...");
         success = forwardTo->process_HEAD_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_HEAD_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_HEAD_Request(request, response)");
      }
      return success;
   }
   //
   // UNKNOWN
   //
   virtual bool process_UNKNOWN_Request(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->process_UNKNOWN_Request(request, response)...");
         success = forwardTo->process_UNKNOWN_Request(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->process_UNKNOWN_Request(request, response)");
      } else {
        LOG_DEBUG("..." << BoolToString(success) << " = process_UNKNOWN_Request(request, response)");
      }
      return success;
   }
   virtual bool processRequest(HttpRequest* request, HttpResponse *response) {
      bool success = false;
      WebSignals* forwardTo = signalsForwardTo();
      if ((forwardTo)) {
         LOG_DEBUG("forwardTo->processRequest(request, response)...");
         success = forwardTo->processRequest(request, response);
         LOG_DEBUG("..." << BoolToString(success) << " = forwardTo->processRequest(request, response)");
      } else {
        LOG_DEBUG("processRequest(request, response)...");
      }
      return success;
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
