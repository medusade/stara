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
//   File: Attached.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_BASE_ATTACHED_H
#define _UNIVERSE_BASE_ATTACHED_H

#include "universe/base/Base.h"

namespace universe {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Enum: AttachStatus
//
enum AttachStatus {
    DetachSuccess,
    AttachSuccess = DetachSuccess,
    AttachFailed,
    DetachFailed
};

//
// Function: attachStatusToChars
//
inline const char* attachStatusToChars(AttachStatus status) {
    switch (status) {
    case AttachSuccess: return "AttachSuccess";
    case AttachFailed: return "AttachFailed";
    case DetachFailed: return "DetachFailed";
    }
    return "Unknown";
}

typedef Exception::Implements AttachExceptionTImplements;
typedef ExceptionT<AttachStatus> AttachExceptionTExtends;
//
// Class: AttachExceptionT
//
template
<class TImplements = AttachExceptionTImplements,
 class TExtends = AttachExceptionTExtends>

class AttachExceptionT: virtual public TImplements, public TExtends {
public:
   typedef TImplements Implements;
   typedef TExtends Extends;
   typedef typename Extends::char_t char_t;

   AttachExceptionT(AttachStatus status): Extends(status) {}
   virtual ~AttachExceptionT() {}
   
   virtual const char_t* reasonToChars() const {
      return attachStatusToChars(this->reason());
   }
};
typedef AttachExceptionT<> AttachException;

typedef ImplementBase AttachTImplements;
//
// Class: AttachT
//
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = AttachException,
 class TImplements = AttachTImplements>

class  AttachT: virtual public TImplements {
public:
   typedef TImplements Implements;
   typedef TException AttachException;

   typedef TAttached Attached;
   typedef TUnattached Unattached_t;
   static const Unattached_t Unattached = VUnattached;

   virtual Attached attach(Attached attachedTo) {
       return ((Attached)Unattached);
   }
   virtual Attached detach() {
       return ((Attached)Unattached);
   }
   virtual bool detached() {
       if (((Attached)Unattached) != (this->attachedTo())) {
           if (((Attached)Unattached) == (this->detach())) {
               return false;
           }
       }
       return true;
   }
   virtual Attached attachedTo() const {
       return ((Attached)Unattached);
   }
   virtual operator Attached() const {
       return attachedTo();
   }
};

typedef Base AttachedTExtends;
//
// Class: AttachedT
//
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = AttachException,
 class TImplements = AttachT
 <TAttached, TUnattached, VUnattached, TException, AttachTImplements>,
 class TExtends = AttachedTExtends>

class AttachedT: virtual public TImplements, public TExtends {
public:
   typedef TImplements Implements;
   typedef TExtends Extends;

   typedef TException AttachException;
   typedef TAttached Attached;
   typedef TUnattached Unattached_t;
   static const Unattached_t Unattached = VUnattached;

   AttachedT(Attached attachedTo): _attachedTo(attachedTo) {
   }
   AttachedT(const AttachedT& copy): _attachedTo(copy._attachedTo) {
   }
   AttachedT(): _attachedTo(((Attached)Unattached)) {
   }
   virtual ~AttachedT() {
       if (!(this->detached())) {
           AttachException e(DetachFailed);
           throw (e);
       }
   }
   virtual Attached attach(Attached attachedTo) {
       return _attachedTo = attachedTo;
   }
   virtual Attached detach() {
       Attached detached = _attachedTo;
       _attachedTo = ((Attached)Unattached);
       return detached;
   }
   virtual Attached attachedTo() const {
       return _attachedTo;
   }
protected:
   Attached _attachedTo;
};

} // namespace universe 

#endif // _UNIVERSE_BASE_ATTACHED_H
