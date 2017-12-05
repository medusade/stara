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
# MacOSX QtCreator .pri file for stara
########################################################################
STARA_OS = macosx

#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -std=c++0x

########################################################################
# libnavajo
LIBNAVAJO_BLD = $${OTHER_BLD}/$${LIBNAVAJO_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
LIBNAVAJO_LIB = $${LIBNAVAJO_BLD}/lib

libnavajo_LIBS += \
-L$${LIBNAVAJO_LIB}/libnavajo \
-lnavajo \

########################################################################
# rostra
ROSTRA_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_LIB = $${ROSTRA_BLD}/lib

rostra_LIBS += \
-L$${ROSTRA_LIB}/librostra \
-lrostra \

########################################################################
# nadir
NADIR_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_LIB = $${NADIR_BLD}/lib

nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \

########################################################################
# stara
stara_INCLUDEPATH += \

stara_DEFINES += \

stara_LIBS += \
$${libnavajo_LIBS} \
$${rostra_LIBS} \
$${build_stara_LIBS} \
$${build_libnavajo_LIBS} \
-lpthread \
-ldl \
