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
#   File: nadir.pri
#
# Author: $author$
#   Date: 12/2/2017
#
# QtCreator .pri file for nadir
########################################################################

OTHER_PKG = ../../../../../../../..
OTHER_BLD = ..

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
NADIR_PKG = ../../../../..
NADIR_BLD = ../..

NADIR_PRJ = $${NADIR_PKG}
NADIR_BIN = $${NADIR_BLD}/bin
NADIR_LIB = $${NADIR_BLD}/lib
NADIR_SRC = $${NADIR_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
nadir_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
nadir_DEFINES += RELEASE_BUILD
}

nadir_INCLUDEPATH += \
$${NADIR_SRC} \
$${rostra_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \

nadir_DEFINES += \
$${rostra_DEFINES} \
$${build_nadir_DEFINES} \

nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \
