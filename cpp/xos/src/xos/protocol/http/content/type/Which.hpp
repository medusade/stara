///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Which.hpp
///
/// Author: $author$
///   Date: 9/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_CONTENT_TYPE_WHICH_HPP
#define _XOS_PROTOCOL_HTTP_CONTENT_TYPE_WHICH_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace content {
namespace type {

///////////////////////////////////////////////////////////////////////
/// Enum: Which
///////////////////////////////////////////////////////////////////////
typedef int Which;
enum {
    None = 0,

    Text,
    Html,
    Xml,
    OctetStream,
    UrlEncodedFormData,
    MultipartFormData,

    Next,
    First = (None + 1),
    Last = (Next - 1),
    Count = ((Last - First) + 1)
};

} // namespace type
} // namespace content 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_CONTENT_TYPE_WHICH_HPP 
