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
# build QtCreator .pri file for stara
########################################################################

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra FRAMEWORKS
#
build_rostra_FRAMEWORKS += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir FRAMEWORKS
#
build_nadir_FRAMEWORKS += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# patrona
#
# pkg-config --cflags --libs patrona
#

# build patrona INCLUDEPATH
#
build_patrona_INCLUDEPATH += \

# build patrona DEFINES
#
build_patrona_DEFINES += \

# build patrona FRAMEWORKS
#
build_patrona_FRAMEWORKS += \

# build patrona LIBS
#
build_patrona_LIBS += \

########################################################################
# crono
#
# pkg-config --cflags --libs crono
#

# build crono INCLUDEPATH
#
build_crono_INCLUDEPATH += \

# build crono DEFINES
#
build_crono_DEFINES += \

# build crono FRAMEWORKS
#
build_crono_FRAMEWORKS += \

# build crono LIBS
#
build_crono_LIBS += \

########################################################################
# fila
#
# pkg-config --cflags --libs fila
#

# build fila INCLUDEPATH
#
build_fila_INCLUDEPATH += \

# build fila DEFINES
#
build_fila_DEFINES += \

# build fila FRAMEWORKS
#
build_fila_FRAMEWORKS += \

# build fila LIBS
#
build_fila_LIBS += \

########################################################################
# rete
#
# pkg-config --cflags --libs rete
#

# build rete INCLUDEPATH
#
build_rete_INCLUDEPATH += \

# build rete DEFINES
#
build_rete_DEFINES += \

# build rete FRAMEWORKS
#
build_rete_FRAMEWORKS += \

# build rete LIBS
#
build_rete_LIBS += \

########################################################################
# stara

# build stara INCLUDEPATH
#
build_stara_INCLUDEPATH += \
$${build_rete_INCLUDEPATH} \
$${build_fila_INCLUDEPATH} \
$${build_crono_INCLUDEPATH} \
$${build_patrona_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \


# build stara DEFINES
#
build_stara_DEFINES += \
$${build_rostra_DEFINES} \
$${build_nadir_DEFINES} \
$${build_patrona_DEFINES} \
$${build_crono_DEFINES} \
$${build_fila_DEFINES} \
$${build_rete_DEFINES} \


# build stara FRAMEWORKS
#
build_stara_FRAMEWORKS += \
$${build_rete_FRAMEWORKS} \
$${build_fila_FRAMEWORKS} \
$${build_crono_FRAMEWORKS} \
$${build_patrona_FRAMEWORKS} \
$${build_nadir_FRAMEWORKS} \
$${build_rostra_FRAMEWORKS} \


# build stara LIBS
#
build_stara_LIBS += \
$${build_rete_LIBS} \
$${build_fila_LIBS} \
$${build_crono_LIBS} \
$${build_patrona_LIBS} \
$${build_nadir_LIBS} \
$${build_rostra_LIBS} \


