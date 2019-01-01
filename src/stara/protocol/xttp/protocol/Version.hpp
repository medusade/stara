///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: Version.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_HPP
#define _STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_HPP

#include "stara/protocol/xttp/message/Part.hpp"

#define STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR "1"
#define STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR "0"

namespace stara {
namespace protocol {
namespace xttp {
namespace protocol {

typedef message::PartTImplements VersionTImplements;
typedef message::Part VersionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: VersionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = VersionTImplements,
 class TExtends = VersionTExtends>

class _EXPORT_CLASS VersionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    VersionT(const char* chars, size_t length)
    : Extends(chars, length),
      m_major(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
        Separate();
    }
    VersionT(const char* chars)
    : Extends(chars),
      m_major(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
        Separate();
    }
    VersionT(const VersionT& copy)
    : Extends(copy),
      m_major(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
    }
    VersionT(const char* major, const char* minor)
    : m_major(major), m_minor(minor) {
        Combine();
    }
    VersionT()
    : m_major(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
        Combine();
    }
    virtual ~VersionT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = false;
        const char *major = 0, *minor = 0;
        if ((major = m_major.has_chars()) && (minor = m_minor.has_chars())) {
            this->assign(major);
            this->append('.');
            this->append(minor);
            success = true;
        }
        return success;
    }
    virtual bool Separate() {
        bool success = false;
        const char* chars = 0;
        size_t length = 0;

        m_major.assign(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR);
        m_minor.assign(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR);

        if ((chars = this->has_chars(length)) && (3 <= length)) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, major, minor;

            for (part = &major; chars != end; ++chars) {
                if ('.' != (c = *chars)) {
                    if (('0' <= c) && ('9' >= c)) {
                        // '0'..'9'
                        part->append(&c, 1);
                    } else {
                        // not '0'..'9'
                        return false;
                    }
                } else {
                    if (part != &minor) {
                        if (major.has_chars()) {
                            // ?'.'
                            part = &minor;
                        } else {
                            // '.'
                            return false;
                        }
                    } else {
                        // ?'.'*'.'
                        return false;
                    }
                }
            }
            if ((major.has_chars()) && (minor.has_chars())) {
                // ?'.'?
                m_major.assign(major);
                m_minor.assign(minor);
                success = true;
            }
        }
        return success;
    }
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        ssize_t amount = 0;
        String chars;
        SetDefault();
        do {
            if (0 < (amount = reader.Read(&c, 1))) {
                count += amount;
                if ((' ' != c) && ('\r' != c) && ('\n' != c)) {
                    chars.append(&c, 1);
                } else {
                    break;
                }
            } else {
                count = amount;
                return false;
            }
        } while (0 < amount);
        if ((chars.has_chars())) {
            this->assign(chars);
            success = Separate();
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual VersionT& SetDefault() {
        m_major.assign(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR);
        m_minor.assign(STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR);
        Combine();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message::Part& SetMajor(const String& to) {
        m_major.assign(to);
        Combine();
        return m_major;
    }
    virtual message::Part& SetMajor(const char* to, size_t length) {
        m_major.assign(to, length);
        Combine();
        return m_major;
    }
    virtual message::Part& SetMajor(const char* to) {
        m_major.assign(to);
        Combine();
        return m_major;
    }
    virtual message::Part& SetMajor(char to) {
        m_major.assign(&to, 1);
        Combine();
        return m_major;
    }
    virtual const message::Part& Major() const {
        return m_major;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message::Part& SetMinor(const String& to) {
        m_minor.assign(to);
        Combine();
        return m_minor;
    }
    virtual message::Part& SetMinor(const char* to, size_t length) {
        m_minor.assign(to, length);
        Combine();
        return m_minor;
    }
    virtual message::Part& SetMinor(const char* to) {
        m_minor.assign(to);
        Combine();
        return m_minor;
    }
    virtual message::Part& SetMinor(char to) {
        m_minor.assign(&to, 1);
        Combine();
        return m_minor;
    }
    virtual const message::Part& Minor() const {
        return m_minor;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    message::Part m_major, m_minor;
};
typedef VersionT<> Version;

} // namespace protocol
} // namespace xttp 
} // namespace protocol 
} // namespace stara 

#endif // _STARA_PROTOCOL_XTTP_PROTOCOL_VERSION_HPP 
