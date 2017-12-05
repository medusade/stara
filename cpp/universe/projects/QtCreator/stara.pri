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
#   File: stara.pri
#
# Author: $author$
#   Date: 12/2/2017
#
# QtCreator .pri file for stara
########################################################################

OTHER_PKG = ../../../../../../../..
OTHER_BLD = ..

########################################################################
# libnavajo
LIBNAVAJO_PKG = $${OTHER_PKG}/../thirdparty/libnavajo/libnavajo
LIBNAVAJO_PRJ = $${LIBNAVAJO_PKG}
LIBNAVAJO_SRC = $${LIBNAVAJO_PKG}/src

libnavajo_INCLUDEPATH += \
$${LIBNAVAJO_PKG}/include \

libnavajo_DEFINES += \

libnavajo_LIBS += \

########################################################################
# rostra
ROSTRA_PKG = $${OTHER_PKG}/rostra/cpp/xos
ROSTRA_PRJ = $${ROSTRA_PKG}
ROSTRA_SRC = $${ROSTRA_PKG}/src

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

rostra_DEFINES += \

rostra_LIBS += \

########################################################################
# nadir
NADIR_PKG = $${OTHER_PKG}/stara/cpp/universe
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \


########################################################################
# stara
STARA_PKG = ../../../../..
STARA_BLD = ../..

STARA_PRJ = $${STARA_PKG}
STARA_BIN = $${STARA_BLD}/bin
STARA_LIB = $${STARA_BLD}/lib
STARA_SRC = $${STARA_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
stara_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
stara_DEFINES += RELEASE_BUILD
}

stara_INCLUDEPATH += \
$${STARA_SRC} \
$${nadir_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \
$${build_stara_INCLUDEPATH} \

stara_DEFINES += \
$${rostra_DEFINES} \
$${nadir_DEFINES} \
$${build_stara_DEFINES} \

stara_LIBS += \
-L$${STARA_LIB}/libstara \
-lstara \
