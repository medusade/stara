########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   File: stara.pro
#
# Author: $author$
#   Date: 9/15/2017
#
# QtCreator .pro file for stara executable stara
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/stara/stara.pri)

TARGET = $${stara_exe_TARGET}

########################################################################
INCLUDEPATH += \
$${stara_exe_INCLUDEPATH} \

DEFINES += \
$${stara_exe_DEFINES} \

########################################################################
HEADERS += \
$${stara_exe_HEADERS} \

SOURCES += \
$${stara_exe_SOURCES} \

########################################################################
LIBS += \
$${stara_exe_LIBS} \
