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
///   File: Part.hpp
///
/// Author: $author$
///   Date: 12/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_MESSAGE_PART_HPP
#define _STARA_PROTOCOL_XTTP_MESSAGE_PART_HPP

#include "stara/protocol/xttp/Xttp.hpp"
#include "stara/io/Reader.hpp"
#include "stara/io/Writer.hpp"
#include <algorithm>

namespace stara {
namespace protocol {
namespace xttp {
namespace message {

typedef StringImplements PartTImplements;
typedef String PartTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: PartT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = PartTImplements, class TExtends = PartTExtends>

class _EXPORT_CLASS PartT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PartT(const String& s)
    : Extends(s) {
    }
    PartT(const char* chars, size_t length)
    : Extends(chars, length) {
    }
    PartT(const char* chars)
    : Extends(chars) {
    }
    PartT(const PartT& copy)
    : Extends(copy) {
    }
    PartT() {
    }
    virtual ~PartT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = true;
        return success;
    }
    virtual bool Separate() {
        bool success = true;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        return success;
    }
    virtual bool Write(ssize_t& count, io::CharWriter& writer) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Set(const String& to) {
        bool success = true;
        this->assign(to);
        success = Separate();
        return success;
    }
    virtual bool Set(const char* to, size_t length) {
        bool success = true;
        this->assign(to, length);
        success = Separate();
        return success;
    }
    virtual bool Set(const char* to) {
        bool success = true;
        this->assign(to);
        success = Separate();
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual PartT& SetDefault() {
        this->clear();
        SetDefaults();
        return *this;
    }
    virtual PartT& SetDefaults() {
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(const String& to) const {
        int unequal = Compare(*this, to, Compare);
        return unequal;
    }
    virtual int UncasedCompare(const String& to) const {
        int unequal = Compare(*this, to, UncasedCompare);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int Compare
    (const String& s, const String& to,
     int compare(const char& c, const char& c2)) {
        int unequal = 0, compared = 0;
        const char *chars = 0, *toChars = 0, *end = 0;
        size_t length = 0, toLength = 0;

        if ((chars = s.has_chars(length))) {
            if ((toChars = to.has_chars(toLength))) {
                if (((end = (chars + length)) - chars) > toLength) {
                    end = (chars + toLength);
                    unequal = 1;
                } else {
                    if (toLength > length) {
                        unequal = -1;
                    }
                }
                for (; chars != end; ++chars, ++toChars) {
                    if ((compared = compare(*chars, *toChars))) {
                        return compared;
                    }
                }
            } else {
                unequal = 1;
            }
        } else {
            if ((toChars = to.has_chars(toLength))) {
                unequal = -1;
            }
        }
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int Compare(const char& c, const char& c2) {
        if (c > c2) { return 1; } else {
            if (c < c2) { return -1; }
        }
        return 0;
    }
    static int UncasedCompare(const char& c, const char& c2) {
        return Compare(std::tolower(c), std::tolower(c2));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef PartT<> Part;

} // namespace message
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_MESSAGE_PART_HPP
