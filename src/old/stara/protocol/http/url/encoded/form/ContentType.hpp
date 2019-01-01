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
///   File: ContentType.hpp
///
/// Author: $author$
///   Date: 3/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_HTTP_URL_ENCODED_FORM_CONTENTTYPE_HPP
#define _STARA_PROTOCOL_HTTP_URL_ENCODED_FORM_CONTENTTYPE_HPP

#include "stara/protocol/xttp/message/Part.hpp"

#define STARA_PROTOCOL_HTTP_URL_ENCODED_FORM_CONTENT_TYPE_NAME \
    "application/x-www-form-urlencoded"

namespace stara {
namespace protocol {
namespace http {
namespace url {
namespace encoded {
namespace form {

typedef stara::protocol::xttp::message::PartTImplements ContentTypeTImplements;
typedef stara::protocol::xttp::message::Part ContentTypeTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ContentTypeT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ContentTypeTImplements, class TExtends = ContentTypeTExtends>

class _EXPORT_CLASS ContentTypeT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ContentTypeT()
    : Extends(STARA_PROTOCOL_HTTP_URL_ENCODED_FORM_CONTENT_TYPE_NAME) {
    }
    ContentTypeT(const ContentTypeT& copy)
    : Extends(copy) {
    }
    virtual ~ContentTypeT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ContentTypeT<> ContentType;

} // namespace form
} // namespace encoded 
} // namespace url 
} // namespace http 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_HTTP_URL_ENCODED_FORM_CONTENTTYPE_HPP 
