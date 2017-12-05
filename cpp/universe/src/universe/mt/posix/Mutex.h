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
//   File: Mutex.h
//
// Author: $author$
//   Date: 12/4/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_MT_POSIX_MUTEX_H
#define _UNIVERSE_MT_POSIX_MUTEX_H

#include "universe/mt/Mutex.h"
#include "universe/logger/Interface.h"

#include <pthread.h>
#include <time.h>
#include <errno.h>

#if defined(HAS_POSIX_TIMEOUTS)
#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#endif // defined(HAS_POSIX_TIMEOUTS)

#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#if !defined(CLOCK_REALTIME)
#define CLOCK_REALTIME 0
#define clockid_t int
inline int clock_gettime
(clockid_t clk_id, struct timespec *res) {
    if ((res)) {
        memset(res, 0, sizeof(struct timespec));
        return 0; 
    }
    return 1; 
}
#else // !defined(CLOCK_REALTIME)
#endif // !defined(CLOCK_REALTIME)
inline int pthread_mutex_timedlock
(pthread_mutex_t *mutex, const struct timespec *abs_timeout) {
    return 1; 
}
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#else // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)

namespace universe {
namespace mt {
namespace posix {

typedef pthread_mutex_t* MutexTAttachedT;
typedef mt::Mutex MutexTAttachImplements;
typedef AttachT<MutexTAttachedT, int, 0, AttachException, MutexTAttachImplements> MutexTAttach;
typedef AttachedT<MutexTAttachedT, int, 0, AttachException, MutexTAttach> MutexTAttached;
typedef CreatedT<MutexTAttachedT, int, 0, CreateException, MutexTAttach, MutexTAttached> MutexTCreated;
typedef MutexTAttach MutexTImplements;
typedef MutexTCreated MutexTExtends;
//
//
//
template
<class TImplements = MutexTImplements, class TExtends = MutexTExtends>

class _EXPORT_CLASS MutexT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

   MutexT(pthread_mutex_t* attachedTo, bool isCreated)
   : Extends(attachedTo, isCreated) {
   }
   MutexT(pthread_mutex_t* attachedTo): Extends(attachedTo) {
   }
   MutexT(bool initallyLocked) {
       if (!(this->create(initallyLocked))) {
           CreateException e(CreateFailed);
           throw (e);
       }
   }
   MutexT() {
       if (!(this->create())) {
           CreateException e(CreateFailed);
           throw (e);
       }
   }
   virtual ~MutexT() {
       if (!(this->destroyed())) {
           CreateException e(DestroyFailed);
           throw (e);
       }
   }

   virtual bool create(bool initallyLocked) {
       if (!(initallyLocked)) {
           return this->create();
       }
       return false;
   }
   virtual bool create() {
       pthread_mutex_t* detached = 0;
       if ((detached = createAttached())) {
           this->setIsCreated();
           return detached;
       }
       return false;
   }
   virtual bool destroy() {
       pthread_mutex_t* detached = 0;
       if ((detached = this->detach())) {
           if ((destroyDetached(detached))) {
               return true;
           }
       }
       return false;
   }
   virtual pthread_mutex_t* createAttached() {
       pthread_mutex_t* detached = 0;
       if ((this->destroyed())) {
           if ((detached = createDetached(_mutexattr, _mutex))) {
               this->attach(detached);
               return detached;
           }
       }
       return 0;
   }
   virtual pthread_mutex_t* createDetached
   (pthread_mutexattr_t& mutexattr, pthread_mutex_t& mutex) const {
       int err = 0;

       IF_LOG_DEBUG("pthread_mutexattr_init(&mutexattr)...");
       if (!(err = pthread_mutexattr_init(&mutexattr))) {

           IF_LOG_DEBUG("pthread_mutex_init(&mutex, &mutexattr)...");
           if (!(err = pthread_mutex_init(&mutex, &mutexattr))) {

               IF_LOG_DEBUG("pthread_mutexattr_destroy(&mutexattr)...");
               if ((err = pthread_mutexattr_destroy(&mutexattr))) {
                   if ((err = pthread_mutex_destroy(&mutex))) {
                   }
                   return 0;
               }
               return &mutex;
           }
           if ((err = pthread_mutexattr_destroy(&mutexattr))) {
           }
       }
       return 0;
   }
   virtual bool destroyDetached(pthread_mutex_t* mutex) const {
       if ((mutex)) {
           int err = 0;
           IF_LOG_DEBUG("pthread_mutex_destroy(mutex)...");
           if (!(err = pthread_mutex_destroy(mutex))) {
               return true;
           } else {
           }
       }
       return false;
   }

   virtual bool lock() {
       pthread_mutex_t* mutex = 0;
       int err = 0;
       if ((mutex = this->_attachedTo)) {
           IF_LOG_DEBUG("pthread_mutex_lock(mutex)...")
           if (!(err = pthread_mutex_lock(mutex))) {
               return true;
           } else {
           }
       }
       return false;
   }
   virtual bool unlock() {
       pthread_mutex_t* mutex = 0;
       int err = 0;
       if ((mutex = this->_attachedTo)) {
           IF_LOG_DEBUG("pthread_mutex_unlock(mutex)...")
           if (!(err = pthread_mutex_unlock(mutex))) {
               return true;
           } else {
           }
       }
       return false;
   }

   virtual LockStatus tryLock() {
       pthread_mutex_t* mutex = 0;
       if ((mutex = this->_attachedTo)) {
           int err = 0;
           IF_LOG_TRACE("pthread_mutex_trylock(mutex)...");
           if ((err =  pthread_mutex_trylock(mutex))) {
               switch(err) {
               case ETIMEDOUT:
                   IF_LOG_TRACE("...ETIMEDOUT err = "<< err << " on pthread_mutex_trylock(mutex)")
                   return LockBusy;
               case EINTR:
                   IF_LOG_ERROR("...EINTR err = "<< err << " on pthread_mutex_trylock(mutex)")
                   return LockInterrupted;
               default:
                   IF_LOG_ERROR("...failed err = "<< err << " on pthread_mutex_trylock(mutex)")
                   return LockFailed;
               }
           } else {
               return LockSuccess;
           }
       }
       return LockFailed;
   }
   virtual LockStatus untimedLock() {
       pthread_mutex_t* mutex = 0;
       if ((mutex = this->_attachedTo)) {
           int err = 0;
           IF_LOG_DEBUG("pthread_mutex_lock(mutex)...")
           if ((err =  pthread_mutex_lock(mutex))) {
               switch(err) {
               case ETIMEDOUT:
                   IF_LOG_ERROR("...ETIMEDOUT err = "<< err << " on pthread_mutex_lock(mutex)")
                   return LockBusy;
               case EINTR:
                   IF_LOG_ERROR("...EINTR err = "<< err << " on pthread_mutex_lock(mutex)")
                   return LockInterrupted;
               default:
                   IF_LOG_ERROR("...failed err = "<< err << " on pthread_mutex_lock(mutex)")
                   return LockFailed;
               }
           } else {
               return LockSuccess;
           }
       }
       return LockFailed;
   }
   virtual LockStatus TimedLock(mseconds_t milliseconds) {
       if (0 < (milliseconds)) {
#if defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
           pthread_mutex_t* mutex = 0;
           if ((mutex = this->_attachedTo)) {
               int err = 0;
               struct timespec untilTime;
               clock_gettime(CLOCK_REALTIME, &untilTime);
               untilTime.tv_sec +=  mseconds_seconds(milliseconds);
               untilTime.tv_nsec +=  mseconds_nseconds(milliseconds);

               IF_LOG_TRACE("pthread_mutex_timedlock(mutex, &untilTime)...");
               if ((err = pthread_mutex_timedlock(mutex, &untilTime))) {
                   switch(err) {
                   case ETIMEDOUT:
                       IF_LOG_TRACE("...ETIMEDOUT err = "<< err << " on pthread_mutex_timedlock(mutex, &untilTime)")
                       return LockBusy;
                   case EINTR:
                       IF_LOG_ERROR("...EINTR err = "<< err << " on pthread_mutex_timedlock(mutex, &untilTime)")
                       return LockInterrupted;
                   default:
                       IF_LOG_ERROR("...failed err = "<< err << " on pthread_mutex_timedlock(mutex, &untilTime)")
                       return LockFailed;
                   }
               } else {
                   return LockSuccess;
               }
           }
#else // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
           IF_LOG_ERROR("...invalid on pthread_mutex_timedlock(mutex, &untilTime)")
           return LockInvalid;
#endif // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
       } else {
           if (milliseconds) {
               return untimedLock();
           } else {
               return tryLock();
           }
       }
       return LockFailed;
   }

protected:
    pthread_mutexattr_t _mutexattr;
    pthread_mutex_t _mutex;
};
typedef MutexT<> Mutex;

} // namespace posix 
} // namespace mt 
} // namespace universe 

#endif // _UNIVERSE_MT_POSIX_MUTEX_H
