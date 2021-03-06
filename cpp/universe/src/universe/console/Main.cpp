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
//   File: Main.cpp
//
// Author: $author$
//   Date: 12/2/2017
//
// Copyright (c) 2017 $organization$
//
#include "universe/console/Main.h"
#include "universe/mt/posix/Mutex.h"

namespace universe {
namespace console {

//
// Class: Class
//

} // namespace console 
} // namespace universe

//
// Function: main
//
int main(int argc, char** argv, char** env) {
   int err = 1;

   ERR_LOG_DEBUG("try {...");
   try {
      universe::mt::posix::Mutex mutex;
      universe::console::IoInstance io(mutex);
      universe::console::Logger logger(io);

      ERR_LOG_DEBUG("universe::console::main(argc, argv, env)...");
      if ((err = universe::console::main(argc, argv, env))) {
         ERR_LOG_ERROR("...err = " << err << " on universe::console::main(argc, argv, env)...");
      }
   } catch (...) {
      ERR_LOG_ERROR("...} catch(...)");
   }
   return err;
}
