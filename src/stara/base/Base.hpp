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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 12/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_BASE_BASE_HPP
#define _STARA_BASE_BASE_HPP

#include "nadir/base/string.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/chars.hpp"
#include "nadir/base/base.hpp"

namespace stara {

typedef ::nadir::implement_base ImplementBase;
typedef ::nadir::base Base;

typedef ::nadir::char_array CharArray;
typedef ::nadir::tchar_array TCharArray;
typedef ::nadir::wchar_array WCharArray;

typedef ::nadir::char_string_implements StringImplements;
typedef ::nadir::tchar_string_implements TStringImplements;
typedef ::nadir::wchar_string_implements WStringImplements;

typedef ::nadir::char_string String;
typedef ::nadir::tchar_string TString;
typedef ::nadir::wchar_string WString;

typedef ::nadir::chars_t Chars;
typedef ::nadir::tchars_t TChars;
typedef ::nadir::wchars_t WChars;

typedef ::nadir::pointer_t pointer_t;
typedef ::nadir::unsigned_t unsigned_t;
typedef ::nadir::signed_t signed_t;

inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

} // namespace stara

#endif // _STARA_BASE_BASE_HPP 
