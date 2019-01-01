########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   Date: 12/12/2016
########################################################################
STARA_PKG = ../../../../..
STARA_BLD = ../..

STARA_PRJ = $${STARA_PRO_DIR}$${STARA_PKG}
STARA_BIN = $${STARA_BLD}/bin
STARA_LIB = $${STARA_BLD}/lib
STARA_SRC = $${STARA_PRJ}/src

CONFIG(debug, debug|release) {
STARA_CONFIG = Debug
stara_DEFINES += DEBUG_BUILD
} else {
STARA_CONFIG = Release
stara_DEFINES += RELEASE_BUILD
}
stara_DEFINES += BUILD_CONFIG=$${STARA_CONFIG}

########################################################################
# NO Qt
QT -= gui core

########################################################################
# patrona
PATRONA_PKG = $${STARA_PKG}/../patrona
PATRONA_PRJ = $${STARA_PRO_DIR}$${PATRONA_PKG}
PATRONA_SRC = $${PATRONA_PRJ}/src

patrona_INCLUDEPATH += \
$${PATRONA_SRC} \

patrona_DEFINES += \

patrona_LIBS += \

########################################################################
# nadir
NADIR_PKG = $${STARA_PKG}/../nadir
NADIR_PRJ = $${STARA_PRO_DIR}$${NADIR_PKG}
NADIR_SRC = $${NADIR_PRJ}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
# crono
CRONO_PKG = $${STARA_PKG}/../crono
CRONO_PRJ = $${STARA_PRO_DIR}$${CRONO_PKG}
CRONO_SRC = $${CRONO_PRJ}/src

crono_INCLUDEPATH += \
$${CRONO_SRC} \

crono_DEFINES += \

crono_LIBS += \

########################################################################
stara_INCLUDEPATH += \
$${STARA_SRC} \
$${crono_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \

stara_DEFINES += \

########################################################################
stara_LIBS += \
-L$${STARA_LIB}/libstara \
-lstara \
