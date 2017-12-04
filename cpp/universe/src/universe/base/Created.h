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
//   File: Created.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_BASE_CREATED_H
#define _UNIVERSE_BASE_CREATED_H

#include "universe/base/Attached.h"

namespace universe {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//
// Enum: CreateStatus
//
enum CreateStatus {
    DestroySuccess,
    CreateSuccess = DestroySuccess,
    CreateFailed,
    DestroyFailed
};

//
// Function: createStatusToChars
//
inline const char* createStatusToChars(CreateStatus status) {
    switch (status) {
    case CreateSuccess: return "CreateSuccess";
    case CreateFailed: return "CreateFailed";
    case DestroyFailed: return "DestroyFailed";
    }
    return "Unknown";
}

typedef Exception::Implements CreateExceptionTImplements;
typedef ExceptionT<CreateStatus> CreateExceptionTExtends;
//
//  Class: CreateExceptionT
//
template
<class TImplements = CreateExceptionTImplements,
 class TExtends = CreateExceptionTExtends>

class  CreateExceptionT: virtual public TImplements, public TExtends {
public:
   typedef TImplements Implements;
   typedef TExtends Extends;
   
   typedef typename Extends::char_t char_t;

   CreateExceptionT(CreateStatus status): Extends(status) {}
   CreateExceptionT(const CreateExceptionT& copy): Extends(copy.Status()) {}
   virtual ~CreateExceptionT() {}

   virtual const char_t* reasonToChars() const {
       return createStatusToChars(this->Status());
   }
};
typedef CreateExceptionT<> CreateException;

typedef ImplementBase CreateTImplements;
//
// Class: CreateT
//
template
<class TException = CreateException, class TImplements = CreateTImplements>

class CreateT: virtual public TImplements {
public:
   typedef TImplements Implements;
   typedef TException CreateException;

   virtual bool create() { return false; }
   virtual bool destroy() { return false; }
   virtual bool created() {
       if (!(isCreated())) {
           return create();
       }
       return true; 
   }
   virtual bool destroyed() {
       if ((isCreated())) {
           return destroy();
       }
       return true; 
   }
   virtual bool setIsCreated(bool isTrue = true) { return false; }
   virtual bool isCreated() const { return false; }
   virtual bool isDestroyed() const { return !isCreated(); }
};
typedef CreateT<> Create;

typedef Create CreatedTImplements;
typedef Base CreatedTExtends;
//
// Class: CreatedT
//
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = CreateException,
 class TImplements = AttachT
  <TAttached, TUnattached, VUnattached, CreatedTImplements>,
 class TExtends = AttachedT
 <TAttached, TUnattached, VUnattached, TImplements, CreatedTExtends> >

class CreatedT: virtual public TImplements, public TExtends {
public:
   typedef TImplements Implements;
   typedef TExtends Extends;

   typedef TException CreateException;
   typedef TAttached Attached;
   static const TUnattached Unattached = VUnattached;

   CreatedT(Attached attachedTo, bool isCreated)
   : Extends(attachedTo), _isCreated(isCreated) {
   }
   CreatedT(const CreatedT& copy)
   : Extends(copy.AttachedTo()), _isCreated(false) {
   }
   CreatedT()
   : Extends(((Attached)Unattached)), _isCreated(false) {
   }
   virtual ~CreatedT() {
       if (!(this->destroyed())) {
           CreateException e(DestroyFailed);
           throw (e);
       }
   }

   virtual bool create() {
       Attached detached = ((Attached)Unattached);
       if (((Attached)Unattached) != (detached = createAttached())) {
           this->setIsCreated();
           return true;
       }
       return false;
   }
   virtual bool destroy() {
       Attached detached = ((Attached)Unattached);
       if (((Attached)Unattached) != (detached = this->detach())) {
           if ((destroyDetached(detached))) {
               return true;
           }
       }
       return false;
   }
   virtual Attached createAttached() {
       Attached detached = ((Attached)Unattached);
       if ((detached = createDetached())) {
           this->attach(detached);
       }
       return detached;
   }
   virtual Attached createDetached() const {
       Attached detached = ((Attached)Unattached);
       return detached;
   }
   virtual bool destroyDetached(Attached detached) const {
       if (((Attached)Unattached) != (detached)) {
           bool success = false;
           return success;
       }
       return false;
   }

   virtual Attached attachCreated
   (Attached attachedTo, bool isCreated = true) {
       attachedTo = this->attach(attachedTo);
       this->setIsCreated(isCreated);
       return attachedTo;
   }
   virtual Attached detachCreated(bool& isCreated){
       Attached detached = this->detach();
       isCreated = this->isCreated();
       this->setIsCreated(false);
       return detached;
   }
   virtual Attached attach(Attached attachedTo) {
       attachedTo = Extends::attach(attachedTo);
       this->setIsCreated(false);
       return attachedTo;
   }
   virtual Attached detach(){
       Attached detached = Extends::detach();
       this->setIsCreated(false);
       return detached;
   }

   virtual bool setIsCreated(bool to = true) {
       _isCreated = to;
       return _isCreated;
   }
   virtual bool isCreated() const {
       return _isCreated;
   }

protected:
   bool _isCreated;
};

} // namespace universe 

#endif // _UNIVERSE_BASE_CREATED_H
