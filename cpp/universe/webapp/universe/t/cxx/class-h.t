%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: class-h.t
%#
%# Author: $author$
%#   Date: 12/2/2017
%#
%# Copyright (c) 2017 $organization$
%#
%with(%
%namespace,%(%else-then(%do(%namespace%)%,%()%)%)%,%
%Namespace,%(%else-then(%do(%Namespace%)%,%(%namespace%)%)%)%,%
%NAMESPACE,%(%else-then(%NAMESPACE%,%(%toupper(%Namespace%)%)%)%)%,%
%namespace,%(%else-then(%_Namespace%,%(%tolower(%Namespace%)%)%)%)%,%
%ifndef,%(%else-then(%do(%ifndef%)%,%(%Namespace%)%)%)%,%
%Ifndef,%(%else-then(%do(%Ifndef%)%,%(%ifndef%)%)%)%,%
%Ifndef,%(%parse(%Ifndef%,/,,_,,%(%Ifndef%)%,Ifndef)%)%,%
%IFNDEF,%(%else-then(%IFNDEF%,%(%toupper(%Ifndef%)%)%)%)%,%
%ifndef,%(%else-then(%_Ifndef%,%(%tolower(%Ifndef%)%)%)%)%,%
%directory,%(%else-then(%do(%directory%)%,%(%Ifndef%)%)%)%,%
%Directory,%(%else-then(%do(%Directory%)%,%(%directory%)%)%)%,%
%DIRECTORY,%(%else-then(%DIRECTORY%,%(%toupper(%Directory%)%)%)%)%,%
%directory,%(%else-then(%_Directory%,%(%tolower(%Directory%)%)%)%)%,%
%include,%(%else-then(%do(%include%)%,%(%if-then(%Directory%,/)%Base.h)%)%)%,%
%Include,%(%else-then(%do(%Include%)%,%(%include%)%)%)%,%
%INCLUDE,%(%else-then(%INCLUDE%,%(%toupper(%Include%)%)%)%)%,%
%include,%(%else-then(%_Include%,%(%tolower(%Include%)%)%)%)%,%
%class,%(%else-then(%do(%class%)%,%(c)%)%)%,%
%Class,%(%else-then(%do(%Class%)%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%implements,%(%else-then(%do(%implements%)%,%()%)%)%,%
%Implements,%(%else-then(%do(%Implements%)%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%do(%extends%)%,%()%)%)%,%
%Extends,%(%else-then(%do(%Extends%)%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%constructor,%(%else-then(%do(%constructor%)%,%()%)%)%,%
%Constructor,%(%else-then(%do(%Constructor%)%,%(%constructor%)%)%)%,%
%CONSTRUCTOR,%(%else-then(%CONSTRUCTOR%,%(%toupper(%Constructor%)%)%)%)%,%
%constructor,%(%else-then(%_Constructor%,%(%tolower(%Constructor%)%)%)%)%,%
%destructor,%(%else-then(%do(%destructor%)%,%()%)%)%,%
%Destructor,%(%else-then(%do(%Destructor%)%,%(%destructor%)%)%)%,%
%DESTRUCTOR,%(%else-then(%DESTRUCTOR%,%(%toupper(%Destructor%)%)%)%)%,%
%destructor,%(%else-then(%_Destructor%,%(%tolower(%Destructor%)%)%)%)%,%
%file,%(%else-then(%do(%file%)%,%(File)%)%)%,%
%File,%(%else-then(%do(%File%)%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%extension,%(%else-then(%do(%extension%)%,%(%filextension(%File%)%)%)%)%,%
%Extension,%(%else-then(%do(%Extension%)%,%(%extension%)%)%)%,%
%Extension,%(%else-then(%Extension%,%(h)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%%(//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: %File%.%Extension%
//
// Author: %Author%
//   Date: %date()%
//
// Copyright (c) %year()% %Organization%
//
#ifndef _%IFNDEF%_%FILE%_%EXTENSION%
#define _%IFNDEF%_%FILE%_%EXTENSION%

%if(%Include%,%(#include "%Include%"
)%)%%if(%IncludeSystem%,%(#include <%IncludeSystem%>
)%)%
%parse(%Namespace%,/,,,,%(namespace %Namespace% {
)%,Namespace)%
%else(%Template%,%(%if(%Implements%,%(typedef ImplementBase %Implements%;
)%)%%if(%Extends%,%(typedef Base %Extends%;
)%)%)%)%//
// Class: %Class%
//%if(%Template%,%(
template 
<%parse(%Template%,;,,%(,
 )%,,%(%Template%)%,Template)%>
)%)%
class %Class%%if(%or(%Implements%,%Extends%)%,%(: )%,)%%then-if(%Implements%,%(virtual %if-then(%ImplementsAccess%, )%)%)%%
%%if(%and(%Implements%,%Extends%)%,%(, )%)%%
%%then-if(%Extends%,%(%if-then(%ExtendsAccess%, )%)%)% {
public:
%if(%Implements%,%(   typedef %Implements% Implements;
)%)%%if(%Extends%,%(   typedef %Extends% Extends;
)%)%%if(%or(%Implements%,%Extends%)%,
)%%if(%Constructor%%Destructor%,%(%
%%if(%Constructor%,%(   %else-yes(%Constructor%,%(%Constructor% )%)%%Class%(const %Class%& copy) {
   }
   %Class%() {
   }
)%)%%if(%Destructor%,%(   %else-yes(%Destructor%,%(%Destructor% )%)%~%Class%() {
   }
)%)%)%)%};

%reverse-parse(%Namespace%,/,,,,%(} // namespace %Namespace% 
)%,Namespace)%

#endif // _%IFNDEF%_%FILE%_%EXTENSION%
)%)%