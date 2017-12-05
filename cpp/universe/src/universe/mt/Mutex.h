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
#ifndef _UNIVERSE_MT_MUTEX_H
#define _UNIVERSE_MT_MUTEX_H

#include "universe/base/Created.h"

namespace universe {
namespace mt {

typedef Logged MutexTLoggedImplements;
typedef Locked MutexTLockedImplements;
typedef Create MutexTCreateImplements;
//
// Class: MutexT
//
template
<class TLoggedImplements = MutexTLoggedImplements,
 class TLockedImplements = MutexTLockedImplements,
 class TCreateImplements = MutexTCreateImplements>
class MutexT
: virtual public TLockedImplements,
  virtual public TLoggedImplements,
  virtual public TCreateImplements {
public:
   typedef TLockedImplements LockedImplements;
   typedef TLoggedImplements LoggedImplements;
   typedef TCreateImplements CreateImplements;
};
typedef MutexT<> Mutex;

} // namespace mt 
} // namespace universe 

#endif // _UNIVERSE_MT_MUTEX_H
