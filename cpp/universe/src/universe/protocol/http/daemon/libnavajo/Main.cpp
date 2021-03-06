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
//   Date: 12/3/2017
//
// Copyright (c) 2017 $organization$
//
#include "universe/protocol/http/daemon/libnavajo/Main.h"
#include "universe/console/Main.cpp"

namespace universe {
namespace protocol {
namespace http {
namespace daemon {
namespace libnavajo {

//
// Class: Main
//

} // namespace libnavajo 
} // namespace daemon 
} // namespace http 
} // namespace protocol 

namespace console {

//
// Function: main
//
int main(int argc, char** argv, char** env) {
   int err = 1;
   protocol::http::daemon::libnavajo::Main main;
   err = protocol::http::daemon::libnavajo::Main::main(argc, argv, env);
   return err;
}

} // namespace console
} // namespace universe 
