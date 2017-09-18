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
///   File: Version.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_HPP
#define _XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_HPP

#include "xos/protocol/xttp/message/Part.hpp"

#define XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR "1"
#define XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR "0"

namespace xos {
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
      m_major(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
        Separate();
    }
    VersionT(const char* chars)
    : Extends(chars),
      m_major(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
        Separate();
    }
    VersionT(const VersionT& copy)
    : Extends(copy),
      m_major(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
    }
    VersionT(const char* major, const char* minor)
    : m_major(major), m_minor(minor) {
        Combine();
    }
    VersionT()
    : m_major(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR),
      m_minor(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR) {
        Combine();
    }
    virtual ~VersionT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = false;
        const char *major = 0, *minor = 0;
        if ((major = m_major.HasChars()) && (minor = m_minor.HasChars())) {
            this->Assign(major);
            this->Append(".");
            this->Append(minor);
            success = true;
        }
        return success;
    }
    virtual bool Separate() {
        bool success = false;
        const char* chars = 0;
        size_t length = 0;

        m_major.Assign(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR);
        m_minor.Assign(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR);

        if ((chars = this->HasChars(length)) && (3 <= length)) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, major, minor;

            for (part = &major; chars != end; ++chars) {
                if ('.' != (c = *chars)) {
                    if (('0' <= c) && ('9' >= c)) {
                        // '0'..'9'
                        part->Append(&c, 1);
                    } else {
                        // not '0'..'9'
                        return false;
                    }
                } else {
                    if (part != &minor) {
                        if (major.HasChars()) {
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
            if ((major.HasChars()) && (minor.HasChars())) {
                // ?'.'?
                m_major.Assign(major);
                m_minor.Assign(minor);
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
                    chars.Append(&c, 1);
                } else {
                    break;
                }
            } else {
                count = amount;
                return false;
            }
        } while (0 < amount);
        if ((chars.HasChars())) {
            this->Assign(chars);
            success = Separate();
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual VersionT& SetDefault() {
        m_major.Assign(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MAJOR);
        m_minor.Assign(XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_MINOR);
        Combine();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message::Part& SetMajor(const String& to) {
        m_major.Assign(to);
        Combine();
        return m_major;
    }
    virtual message::Part& SetMajor(const char* to, size_t length) {
        m_major.Assign(to, length);
        Combine();
        return m_major;
    }
    virtual message::Part& SetMajor(const char* to) {
        m_major.Assign(to);
        Combine();
        return m_major;
    }
    virtual message::Part& SetMajor(char to) {
        m_major.Assign(&to, 1);
        Combine();
        return m_major;
    }
    virtual const message::Part& Major() const {
        return m_major;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual message::Part& SetMinor(const String& to) {
        m_minor.Assign(to);
        Combine();
        return m_minor;
    }
    virtual message::Part& SetMinor(const char* to, size_t length) {
        m_minor.Assign(to, length);
        Combine();
        return m_minor;
    }
    virtual message::Part& SetMinor(const char* to) {
        m_minor.Assign(to);
        Combine();
        return m_minor;
    }
    virtual message::Part& SetMinor(char to) {
        m_minor.Assign(&to, 1);
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
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_PROTOCOL_VERSION_HPP 
