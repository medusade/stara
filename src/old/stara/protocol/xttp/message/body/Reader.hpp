///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: Reader.hpp
///
/// Author: $author$
///   Date: 12/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_BODY_READER_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_BODY_READER_HPP

#include "stara/io/Reader.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace message {
namespace body {

typedef io::CharReader CharReaderTImplements;
typedef Base CharReaderTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CharReaderT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CharReaderTImplements, class TExtends = CharReaderTExtends>

class _EXPORT_CLASS CharReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef Implements reader_t;
    typedef typename Implements::what_t what_t;
    typedef typename Implements::sized_t sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharReaderT(reader_t& reader, size_t length)
    : reader_(reader), length_(length), tell_(0) {
    }
    virtual ~CharReaderT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        sized_t* sized = 0;

        if ((sized = ((sized_t*)what)) && (size)) {
            if (length_ < (tell_ + size)) {
                size = tell_ - length_;
            }
            if ((size)) {
                ssize_t count = 0;

                if (0 < (count = reader_.Read(what, size))) {
                    tell_ += count;
                }
                return count;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_t& reader_;
    size_t length_, tell_;
};
typedef CharReaderT<> CharReader;

} // namespace body
} // namespace message 
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_BODY_READER_HPP 
