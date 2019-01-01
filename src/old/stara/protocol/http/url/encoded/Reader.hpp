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
///   File: Reader.hpp
///
/// Author: $author$
///   Date: 3/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_HTTP_URL_ENCODED_READER_HPP
#define _STARA_PROTOCOL_HTTP_URL_ENCODED_READER_HPP

#include "stara/io/Reader.hpp"

#define STARA_PROTOCOL_HTTP_URL_ENCODED_READER_CHAR_IS_X(x) \
    (((x) >= '0' && (x) <= '9') \
    || ((x) >= 'a' && (x) <= 'f') \
    || ((x) >= 'A' && (x) <= 'F'))

#define STARA_PROTOCOL_HTTP_URL_ENCODED_READER_X_TO_CHAR(x) \
    (((x) >= '0' && (x) <= '9')?((x)-'0') \
    :(((x) >= 'a' && (x) <= 'f')?((x)-'a'+10) \
    :((x)-'A'+10)))

namespace stara {
namespace protocol {
namespace http {
namespace url {
namespace encoded {

typedef io::CharReader CharReaderTImplements;
typedef stara::Base CharReaderTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CharReaderT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CharReaderTImplements, class TExtends = CharReaderTExtends>

class _EXPORT_CLASS CharReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImplements CharReader;
    typedef typename TImplements::sized_t sized_t;
    typedef typename TImplements::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharReaderT(CharReader& reader): m_reader(reader) {
    }
    virtual ~CharReaderT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        sized_t* sized = 0;

        if ((sized = ((sized_t*)what)) && (size)) {
            ssize_t count = 0, amount = 0;
            byte_t x1 = 0, x2 = 0;
            char c = 0;

            while (count < size) {
                if (0 < (amount = m_reader.Read(sized, 1))) {
                    switch (c = ((char)*sized)) {
                    case '%':
                        if (0 < (amount = ReadX(x1, sized))) {
                            if (0 < (amount = ReadX(x2, sized))) {
                                *sized = ((sized_t)((x1 << 4) | x2));
                            } else {
                                return amount;
                            }
                        } else {
                            return amount;
                        }
                        break;

                    case '+':
                        *sized = ((sized_t)' ');
                        break;

                    default:
                        break;
                    }
                    ++sized;
                    ++count;
                } else {
                    return amount;
                }
            }
            return count;
        }
        return 0;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadX(byte_t& x, what_t* what) {
        sized_t* sized = 0;

        if ((sized = ((sized_t*)what))) {
            ssize_t amount = 0;

            if (0 < (amount = m_reader.Read(what, 1))) {
                const char c = ((char)*sized);

                if (STARA_PROTOCOL_HTTP_URL_ENCODED_READER_CHAR_IS_X(c)) {
                    x = STARA_PROTOCOL_HTTP_URL_ENCODED_READER_X_TO_CHAR(c);
                } else {
                    return 0;
                }
            }
            return amount;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    CharReader& m_reader;
};
typedef CharReaderT<> CharReader;

} // namespace encoded 
} // namespace url 
} // namespace http 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_HTTP_URL_ENCODED_READER_HPP
