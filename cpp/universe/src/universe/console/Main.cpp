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

namespace universe {
namespace console {

//
// Class: Class
//

} // namespace console 
} // namespace universe

int main(int argc, char** argv, char** env) {
   int err = 1;
   try {
      universe::console::Main main;
      err = universe::console::Main::main(argc, argv, env);
   } catch (...) {
   }
   return err;
}