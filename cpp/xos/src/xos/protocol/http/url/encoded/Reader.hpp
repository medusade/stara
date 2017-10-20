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
///   Date: 9/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_HTTP_URL_ENCODED_READER_HPP
#define _XOS_PROTOCOL_HTTP_URL_ENCODED_READER_HPP

#include "xos/io/Reader.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace url {
namespace encoded {

typedef io::CharReadObserver CharReaderTObserver;
typedef io::CharReader CharReaderTImplements;
typedef Base CharReaderTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CharReaderT
///////////////////////////////////////////////////////////////////////
template
<class TObserver = CharReaderTObserver,
 class TImplements = CharReaderTImplements, class TExtends = CharReaderTExtends>

class _EXPORT_CLASS CharReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef CharReaderT Derives;

    typedef TObserver observer_t;
    typedef Implements reader_t;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::what_t what_t;
    typedef typename Implements::sized_t sized_t;
    typedef typename Implements::sized_t end_t;
    enum { end = 0 };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharReaderT(observer_t& observer, reader_t& reader)
    : observer_(observer), reader_(reader) {
    }
    CharReaderT(reader_t& reader)
    : observer_(nullObserver_), reader_(reader) {
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
                if (0 < (amount = reader_.Read(sized, 1))) {
                    observer_.OnRead(what, amount);
                    switch (c = ((char)*sized)) {
                    case '%':
                        if (0 >= (amount = ReadX(x1, x2, sized))) {
                            return amount;
                        }
                        *sized = ((sized_t)((x1 << 4) | (x2 & 15)));
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
    virtual ssize_t ReadX(byte_t& x1, byte_t& x2, what_t* what) {
        ssize_t count = 0, amount = 0;

        if (0 < (amount = ReadX(x1, what))) {
            count += amount;
            if (0 < (amount = ReadX(x2, what))) {
                count += amount;
            } else {
                return amount;
            }
        } else {
            return amount;
        }
        return count;
    }
    virtual ssize_t ReadX(byte_t& x, what_t* what) {
        sized_t* sized = 0;

        if ((sized = ((sized_t*)what))) {
            ssize_t amount = 0;
            char c = 0;

            if (0 < (amount = reader_.Read(what, 1))) {
                observer_.OnRead(what, amount);
                c = ((char)*sized);
                if (CharIsX(c)) {
                    x = CharToX(c);
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
    static inline bool CharIsX(sized_t x) {
        return (((x) >= '0' && (x) <= '9')
               || ((x) >= 'a' && (x) <= 'f')
               || ((x) >= 'A' && (x) <= 'F'));
    }
    static inline byte_t CharToX(sized_t x) {
        return (((x) >= '0' && (x) <= '9')?((x)-'0')
               :(((x) >= 'a' && (x) <= 'f')?((x)-'a'+10)
               :((x)-'A'+10)));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    observer_t nullObserver_, &observer_;
    reader_t &reader_;
};
typedef CharReaderT<> CharReader;

} // namespace encoded
} // namespace url 
} // namespace http 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_HTTP_URL_ENCODED_READER_HPP 
