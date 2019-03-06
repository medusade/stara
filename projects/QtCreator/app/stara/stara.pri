########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: stara.pri
#
# Author: $author$
#   Date: 12/31/2018
#
# QtCreator .pri file for stara executable stara
########################################################################

########################################################################
# stara

# stara_exe TARGET
#
stara_exe_TARGET = stara

# stara_exe INCLUDEPATH
#
stara_exe_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# stara_exe DEFINES
#
stara_exe_DEFINES += \
$${stara_DEFINES} \

########################################################################
# stara_exe OBJECTIVE_HEADERS
#
#stara_exe_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# stara_exe OBJECTIVE_SOURCES
#
#stara_exe_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# stara_exe HEADERS
#
stara_exe_HEADERS += \
$${STARA_SRC}/stara/console/lib/stara/version/Main.hpp \
$${STARA_SRC}/stara/app/console/stara/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/stara/Main.hpp \

# stara_exe SOURCES
#
stara_exe_SOURCES += \
$${STARA_SRC}/stara/app/console/stara/MainOpt.cpp \
$${STARA_SRC}/stara/app/console/stara/Main.cpp \

########################################################################
# stara_exe FRAMEWORKS
#
stara_exe_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# stara_exe LIBS
#
stara_exe_LIBS += \
$${stara_LIBS} \


