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
///   File: Line.hpp
///
/// Author: $author$
///   Date: 12/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_LINE_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_LINE_HPP

#include "stara/protocol/xttp/message/Part.hpp"

namespace stara {
namespace protocol {
namespace xttp {
namespace message {

typedef message::PartTImplements LineTImplements;
typedef message::Part LineTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LineT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = LineTImplements,
 class TExtends = LineTExtends>

class _EXPORT_CLASS LineT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LineT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    LineT(const char* chars)
    : Extends(chars) {
    }
    LineT(const LineT& copy)
    : Extends(copy) {
    }
    LineT() {
    }
    virtual ~LineT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        char cr = 0;
        ssize_t amount = 0;
        String chars;
        this->SetDefault();
        do {
            if (0 < (amount = reader.Read(&c, 1))) {
                count += amount;
                if (('\r' != c)) {
                    if (('\n' != c)) {
                        chars.append(&c, 1);
                    } else {
                        success = this->Set(chars);
                        break;
                    }
                } else {
                    if (cr != c) {
                        cr = c;
                    } else {
                        chars.append(&cr, 1);
                    }
                }
            } else {
                count = amount;
                break;
            }
        } while (0 < amount);
        return success;
    }
    virtual bool Write(ssize_t& count, io::CharWriter& writer) {
        bool success = false;
        const char* chars = 0;
        size_t length = 0;
        ssize_t amount = 0;
        if ((chars = this->has_chars(length))) {
            if (length <= (amount = writer.Write(chars, length))) {
                count = amount;
                if (2 <= (amount = writer.Write("\r\n"))) {
                    count += amount;
                    success = true;
                }
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LineT<> Line;

} // namespace message
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_LINE_HPP 
