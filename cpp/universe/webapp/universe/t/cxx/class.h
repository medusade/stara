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
//   File: c.h
//
// Author: $author$
//   Date: 12/3/2017
//
// Copyright (c) 2017 $organization$
//
#ifndef _UNIVERSE_C_H
#define _UNIVERSE_C_H

#include "universe/base/Base.h"
#include <string>

namespace universe {

typedef ImplementBase cImplements;
typedef Base cExtends;
//
// Class: c
//
class c
: virtual public cImplements, public cExtends
{
public:
   typedef cImplements Implements;
   typedef cExtends Extends;

   c(const c& copy)
   {
   }
   c()
   {
   }
   virtual ~c()
   {
   }
};

} // namespace universe 


#endif // _UNIVERSE_C_H
