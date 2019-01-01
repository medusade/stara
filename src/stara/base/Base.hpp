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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_BASE_BASE_HPP
#define _STARA_BASE_BASE_HPP

#include "nadir/base/base.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/to_string.hpp"
#include "nadir/base/chars.hpp"

namespace stara {

typedef ::nadir::pointer_t pointer_t;
typedef ::nadir::unsigned_t unsigned_t;
typedef ::nadir::signed_t signed_t;

inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return nadir::mseconds_seconds(mseconds); }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return nadir::mseconds_mseconds(mseconds); }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return nadir::mseconds_useconds(mseconds); }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return nadir::mseconds_nseconds(mseconds); }

typedef ::nadir::implement_base ImplementBase;
typedef ::nadir::base Base;

typedef ::nadir::char_array char_array;
typedef ::nadir::tchar_array tchar_array;
typedef ::nadir::wchar_array wchar_array;
///////////////////////////////////////////////////////////////////////
///  Class: arrayt
///////////////////////////////////////////////////////////////////////
template <class TExtends>
class _EXPORT_CLASS arrayt: public TExtends {
public:
    typedef TExtends Extends;
    typedef typename Extends::what_t what_t;
    typedef typename Extends::size_t size_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    arrayt(const what_t* elements, size_t length): Extends(elements, length) {
    }
    arrayt(ssize_t length): Extends(length) {
    }
    arrayt(const arrayt& copy): Extends(copy) {
    }
    arrayt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS arrayt

typedef arrayt<char_array> CharArray;
typedef arrayt<tchar_array> TCharArray;
typedef arrayt<wchar_array> WCharArray;

typedef ::nadir::char_string char_string;
typedef ::nadir::tchar_string tchar_string;
typedef ::nadir::wchar_string wchar_string;
///////////////////////////////////////////////////////////////////////
///  Class: char_stringt
///////////////////////////////////////////////////////////////////////
template <class TExtends>
class _EXPORT_CLASS char_stringt: public TExtends {
public:
    typedef TExtends Extends;
    typedef typename Extends::Implements Implements;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_stringt(const char* chars): Extends(chars) {
    }
    char_stringt(const char* chars, size_t length): Extends(chars, length) {
    }
    char_stringt(const wchar_t* chars): Extends(chars) {
    }
    char_stringt(const wchar_t* chars, size_t length): Extends(chars, length) {
    }
    char_stringt(const unsigned_t& c): Extends(c) {
    }
    char_stringt(const signed_t& c): Extends(c) {
    }
    char_stringt(const bool& c): Extends(c) {
    }
    char_stringt(const Extends& copy): Extends(copy) {
    }
    char_stringt(const char_stringt& copy): Extends(copy) {
    }
    char_stringt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* HasChars(size_t& length) const {
        return this->has_chars(length);
    }
    virtual const char_t* HasChars() const {
        return this->has_chars();
    }
    virtual const char_t* Chars(size_t& length) const {
        return this->chars(length);
    }
    virtual const char_t* Chars() const {
        return this->chars();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TExtends& append_bool(const bool& c) {
        this->append((c)?("true"):("false"));
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS char_stringt

typedef char_stringt<char_string> String;
typedef char_stringt<tchar_string> TString;
typedef char_stringt<wchar_string> WString;

typedef String::Implements StringImplements;
typedef TString::Implements TStringImplements;
typedef WString::Implements WStringImplements;

typedef ::nadir::charst<char> chars_t;
typedef ::nadir::charst<wchar_t> wchars_t;
typedef ::nadir::charst<tchar_t> tchars_t;
///////////////////////////////////////////////////////////////////////
///  Class: charst
///////////////////////////////////////////////////////////////////////
template <typename TChar, class TExtends>
class _EXPORT_CLASS charst: public TExtends {
public:
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    typedef typename Extends::end_char_t end_char_t;
    enum { end_char = Extends::end_char };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static signed ToSigned
    (const char_t* what, ssize_t length = -1, end_char_t end = end_char) {
        signed value = Extends::to_signed(what, length, end);
        return value;
    }
    static unsigned ToUnsigned
    (const char_t* what, ssize_t length = -1, end_char_t end = end_char) {
        unsigned value = Extends::to_unsigned(what, length, end);
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS charst

typedef charst<char,chars_t> Chars;
typedef charst<wchar_t,wchars_t> WChars;
typedef charst<tchar_t,tchars_t> TChars;

///////////////////////////////////////////////////////////////////////
///  Class: chars_to_stringt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar, class TString, 
 class TExtends = ::nadir::chars_to_stringt<TChar, TString> >
class _EXPORT_CLASS chars_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    chars_to_stringt(const char* chars): Extends(chars) {
    }
    chars_to_stringt(const wchar_t* chars): Extends(chars) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS chars_to_stringt

typedef chars_to_stringt<char,String> CharsToString;
typedef chars_to_stringt<tchar_t,TString> CharsToTString;
typedef chars_to_stringt<wchar_t,WString> CharsToWString;

///////////////////////////////////////////////////////////////////////
///  Class: bool_to_stringt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar, class TString, 
 class TExtends = ::nadir::bool_to_stringt<TChar, TString> >
class _EXPORT_CLASS bool_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool_to_stringt(const bool& to): Extends(to) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef bool_to_stringt<char,String> BoolToString;
typedef bool_to_stringt<tchar_t,TString> BoolToTString;
typedef bool_to_stringt<wchar_t,WString> BoolToWString;

///////////////////////////////////////////////////////////////////////
///  Class: int_to_stringt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar, class TString, 
 class TExtends = ::nadir::int_to_stringt<TChar, TString> >
class _EXPORT_CLASS int_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int_to_stringt(const int& to): Extends(to) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef int_to_stringt<char,String> IntToString;
typedef int_to_stringt<tchar_t,TString> IntToTString;
typedef int_to_stringt<wchar_t,WString> IntToWString;

///////////////////////////////////////////////////////////////////////
///  Class: signed_to_stringt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar, class TString, 
 class TExtends = ::nadir::signed_to_stringt<TChar, TString> >
class _EXPORT_CLASS signed_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    signed_to_stringt(const signed& to): Extends(to) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef signed_to_stringt<char,String> SignedToString;
typedef signed_to_stringt<tchar_t,TString> SignedToTString;
typedef signed_to_stringt<wchar_t,WString> SignedToWString;

///////////////////////////////////////////////////////////////////////
///  Class: unsigned_to_stringt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar, class TString, 
 class TExtends = ::nadir::unsigned_to_stringt<TChar, TString> >
class _EXPORT_CLASS unsigned_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    unsigned_to_stringt(const unsigned& to): Extends(to) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef unsigned_to_stringt<char,String> UnsignedToString;
typedef unsigned_to_stringt<tchar_t,TString> UnsignedToTString;
typedef unsigned_to_stringt<wchar_t,WString> UnsignedToWString;

///////////////////////////////////////////////////////////////////////
///  Class: pointer_to_stringt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar, class TString, 
 class TExtends = ::nadir::pointer_to_stringt<TChar, TString> >
class _EXPORT_CLASS pointer_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pointer_to_stringt(const pointer_t to): Extends(to) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pointer_to_stringt<char,String> PointerToString;
typedef pointer_to_stringt<tchar_t,TString> PointerToTString;
typedef pointer_to_stringt<wchar_t,WString> PointerToWString;

} // namespace stara

#endif // _STARA_BASE_BASE_HPP 
