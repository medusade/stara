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
# Os QtCreator .pri file for stara
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
STARA_OS = macosx
} else {
STARA_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${STARA_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${STARA_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${STARA_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${STARA_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${STARA_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${STARA_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# patrona
PATRONA_THIRDPARTY_PKG_MAKE_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${STARA_OS}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_MAKE_BLD = $${PATRONA_THIRDPARTY_PRJ}/build/$${STARA_OS}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PKG_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_BLD = $${PATRONA_THIRDPARTY_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
PATRONA_PKG_BLD = $${OTHER_BLD}/$${PATRONA_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
PATRONA_PRJ_BLD = $${OTHER_BLD}/$${PATRONA_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_BLD}/lib
#PATRONA_LIB = $${PATRONA_PKG_BLD}/lib
PATRONA_LIB = $${PATRONA_PRJ_BLD}/lib
#PATRONA_LIB = $${STARA_LIB}

# patrona LIBS
#
patrona_LIBS += \
-L$${PATRONA_LIB}/lib$${PATRONA_NAME} \
-l$${PATRONA_NAME} \

########################################################################
# crono
CRONO_THIRDPARTY_PKG_MAKE_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${STARA_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_MAKE_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${STARA_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PKG_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PKG_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PRJ_BLD = $${OTHER_BLD}/$${CRONO_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_BLD}/lib
#CRONO_LIB = $${CRONO_PKG_BLD}/lib
CRONO_LIB = $${CRONO_PRJ_BLD}/lib
#CRONO_LIB = $${STARA_LIB}

# crono LIBS
#
crono_LIBS += \
-L$${CRONO_LIB}/lib$${CRONO_NAME} \
-l$${CRONO_NAME} \

########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${STARA_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${STARA_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
#FILA_LIB = $${FILA_PKG_BLD}/lib
FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${STARA_LIB}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_NAME} \
-l$${FILA_NAME} \

########################################################################
# rete
RETE_THIRDPARTY_PKG_MAKE_BLD = $${RETE_THIRDPARTY_PKG}/build/$${STARA_OS}/$${BUILD_CONFIG}
RETE_THIRDPARTY_PRJ_MAKE_BLD = $${RETE_THIRDPARTY_PRJ}/build/$${STARA_OS}/$${BUILD_CONFIG}
RETE_THIRDPARTY_PKG_BLD = $${RETE_THIRDPARTY_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
RETE_THIRDPARTY_PRJ_BLD = $${RETE_THIRDPARTY_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
RETE_PKG_BLD = $${OTHER_BLD}/$${RETE_PKG}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
RETE_PRJ_BLD = $${OTHER_BLD}/$${RETE_PRJ}/build/$${STARA_OS}/QtCreator/$${BUILD_CONFIG}
#RETE_LIB = $${RETE_THIRDPARTY_PKG_MAKE_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PRJ_MAKE_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PKG_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PRJ_BLD}/lib
#RETE_LIB = $${RETE_PKG_BLD}/lib
RETE_LIB = $${RETE_PRJ_BLD}/lib
#RETE_LIB = $${STARA_LIB}

# rete LIBS
#
rete_LIBS += \
-L$${RETE_LIB}/lib$${RETE_NAME} \
-l$${RETE_NAME} \

########################################################################
# stara

# stara INCLUDEPATH
#
stara_INCLUDEPATH += \

# stara DEFINES
#
stara_DEFINES += \

# stara LIBS
#
stara_LIBS += \
$${rete_LIBS} \
$${fila_LIBS} \
$${crono_LIBS} \
$${patrona_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \
$${build_stara_LIBS} \
-lpthread \
-ldl \

contains(STARA_OS,linux) {
stara_LIBS += \
-lrt
} else {
}

