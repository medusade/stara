%########################################################################
%# Copyright (c) 1988-2017 $organization$
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
%#   File: stara-qtcreator-exe-pri.t
%#
%# Author: $author$
%#   Date: 3/4/2017
%########################################################################
%with(%
%target,%(%else-then(%target%,%(Target)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%%(########################################################################
# Copyright (c) 1988-%year()% $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: %Target%.pri
#
# Author: $author$
#   Date: %date()%
########################################################################

%Target%_TARGET = stara-%Target%

########################################################################
%Target%_INCLUDEPATH += \
$${stara_INCLUDEPATH} \
$${rete_INCLUDEPATH} \
$${fila_INCLUDEPATH} \

%Target%_DEFINES += \
$${stara_DEFINES} \

########################################################################
%Target%_HEADERS += \

%Target%_SOURCES += \

########################################################################
%Target%_HEADERS += \
$${STARA_SRC}/stara/console/getopt/MainOpt.hpp \
$${STARA_SRC}/stara/console/getopt/Main.hpp \
$${STARA_SRC}/stara/console/Main.hpp \
$${STARA_SRC}/stara/console/Main_main.hpp \
$${STARA_SRC}/stara/app/console/%Target%/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/%Target%/Main.hpp \

%Target%_SOURCES += \
$${STARA_SRC}/stara/app/console/%Target%/Main.cpp \

########################################################################
%Target%_LIBS += \
$${stara_LIBS} \

)%)%