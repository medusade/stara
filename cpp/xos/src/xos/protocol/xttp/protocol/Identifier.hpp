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
///   File: Identifier.hpp
///
/// Author: $author$
///   Date: 9/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_PROTOCOL_XTTP_PROTOCOL_IDENTIFIER_HPP
#define _XOS_PROTOCOL_XTTP_PROTOCOL_IDENTIFIER_HPP

#include "xos/protocol/xttp/protocol/Name.hpp"
#include "xos/protocol/xttp/protocol/Version.hpp"
#include "xos/protocol/xttp/message/Part.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace protocol {

typedef message::PartTImplements IdentifierTImplements;
typedef message::Part IdentifierTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: IdentifierT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = IdentifierTImplements,
 class TExtends = IdentifierTExtends>

class _EXPORT_CLASS IdentifierT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    IdentifierT(const char* chars, size_t length)
    : Extends(chars, length) {
        Separate();
    }
    IdentifierT(const char* chars)
    : Extends(chars) {
        Separate();
    }
    IdentifierT
    (const protocol::Name& name, const protocol::Version& version)
    : m_name(name), m_version(version) {
        Combine();
    }
    IdentifierT(const IdentifierT& copy)
    : Extends(copy),
      m_name(copy.Name()), m_version(copy.Version()) {
    }
    IdentifierT() {
        Combine();
    }
    virtual ~IdentifierT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Combine() {
        bool success = false;
        const char *name = 0, *version = 0;
        if ((name = m_name.HasChars())
            && (version = m_version.HasChars())) {
            this->Assign(name);
            this->Append("/");
            this->Append(version);
            return true;
        }
        return success;
    }
    virtual bool Separate() {
        bool success = false;
        const char* chars = 0;
        size_t length = 0;

        m_name.SetDefault();
        m_version.SetDefault();

        if ((chars = this->HasChars(length))) {
            char c = 0;
            const char* end = chars + length;
            String *part = 0, name, version;

            for (part = &name; chars != end; ++chars) {
                if ('/' != (c = *chars)) {
                    part->Append(&c, 1);
                } else {
                    if (part != &version) {
                        if (name.HasChars()) {
                            // ?'/'
                            part = &version;
                        } else {
                            // '/'
                            return false;
                        }
                    } else {
                        // ?'/'*'/'
                        return false;
                    }
                }
            }
            if ((name.HasChars()) && (version.HasChars())) {
                // ?'/'?
                m_name.Set(name);
                m_version.Set(version);
                success = true;
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, char& c, io::CharReader& reader) {
        bool success = false;
        SetDefault();
        if ((m_name.Read(count, c, reader))) {
            if ((m_version.Read(count, c, reader))) {
                success = Combine();
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual IdentifierT& SetDefault() {
        m_name.SetDefault();
        m_version.SetDefault();
        Combine();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual protocol::Name& SetName(const String& to) {
        m_name.Set(to);
        Combine();
        return m_name;
    }
    virtual const protocol::Name& Name() const {
        return m_name;
    }
    virtual const protocol::Version& Version() const {
        return m_version;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    protocol::Name m_name;
    protocol::Version m_version;
};
typedef IdentifierT<> Identifier;

} // namespace protocol
} // namespace xttp 
} // namespace protocol 
} // namespace xos 

#endif // _XOS_PROTOCOL_XTTP_PROTOCOL_IDENTIFIER_HPP 
