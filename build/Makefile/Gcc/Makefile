########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: Makefile
#
# Author: $author$
#   Date: 4/9/2019
#
# build Gcc Makefile for stara
########################################################################


########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

ifndef USE_HOME_BUILD_rostra
USE_HOME_BUILD_rostra = no
endif

ifeq ($(USE_HOME_BUILD_rostra),yes)
#
# home build rostra
#
build_rostra_USRDEFINES += \

build_rostra_USRINCLUDES += \
-I$(HOME)/build/rostra/include \

build_rostra_USRCXXFLAGS += \

build_rostra_USRLIBDIRS += \
-L$(HOME)/build/rostra/lib \

build_rostra_LIBS += \
-lrostra \

build_rostra_FRAMEWORKS += \

else
#
# build rostra
#
build_rostra_USRDEFINES += \

build_rostra_USRINCLUDES += \

build_rostra_USRCXXFLAGS += \

build_rostra_USRLIBDIRS += \

build_rostra_LIBS += \

build_rostra_FRAMEWORKS += \

endif

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

ifndef USE_HOME_BUILD_nadir
USE_HOME_BUILD_nadir = no
endif

ifeq ($(USE_HOME_BUILD_nadir),yes)
#
# home build nadir
#
build_nadir_USRDEFINES += \

build_nadir_USRINCLUDES += \
-I$(HOME)/build/nadir/include \

build_nadir_USRCXXFLAGS += \

build_nadir_USRLIBDIRS += \
-L$(HOME)/build/nadir/lib \

build_nadir_LIBS += \
-lnadir \

build_nadir_FRAMEWORKS += \

else
#
# build nadir
#
build_nadir_USRDEFINES += \

build_nadir_USRINCLUDES += \

build_nadir_USRCXXFLAGS += \

build_nadir_USRLIBDIRS += \

build_nadir_LIBS += \

build_nadir_FRAMEWORKS += \

endif

########################################################################
# patrona
#
# pkg-config --cflags --libs patrona
#

ifndef USE_HOME_BUILD_patrona
USE_HOME_BUILD_patrona = no
endif

ifeq ($(USE_HOME_BUILD_patrona),yes)
#
# home build patrona
#
build_patrona_USRDEFINES += \

build_patrona_USRINCLUDES += \
-I$(HOME)/build/patrona/include \

build_patrona_USRCXXFLAGS += \

build_patrona_USRLIBDIRS += \
-L$(HOME)/build/patrona/lib \

build_patrona_LIBS += \
-lpatrona \

build_patrona_FRAMEWORKS += \

else
#
# build patrona
#
build_patrona_USRDEFINES += \

build_patrona_USRINCLUDES += \

build_patrona_USRCXXFLAGS += \

build_patrona_USRLIBDIRS += \

build_patrona_LIBS += \

build_patrona_FRAMEWORKS += \

endif

########################################################################
# crono
#
# pkg-config --cflags --libs crono
#

ifndef USE_HOME_BUILD_crono
USE_HOME_BUILD_crono = no
endif

ifeq ($(USE_HOME_BUILD_crono),yes)
#
# home build crono
#
build_crono_USRDEFINES += \

build_crono_USRINCLUDES += \
-I$(HOME)/build/crono/include \

build_crono_USRCXXFLAGS += \

build_crono_USRLIBDIRS += \
-L$(HOME)/build/crono/lib \

build_crono_LIBS += \
-lcrono \

build_crono_FRAMEWORKS += \

else
#
# build crono
#
build_crono_USRDEFINES += \

build_crono_USRINCLUDES += \

build_crono_USRCXXFLAGS += \

build_crono_USRLIBDIRS += \

build_crono_LIBS += \

build_crono_FRAMEWORKS += \

endif

########################################################################
# fila
#
# pkg-config --cflags --libs fila
#

ifndef USE_HOME_BUILD_fila
USE_HOME_BUILD_fila = no
endif

ifeq ($(USE_HOME_BUILD_fila),yes)
#
# home build fila
#
build_fila_USRDEFINES += \

build_fila_USRINCLUDES += \
-I$(HOME)/build/fila/include \

build_fila_USRCXXFLAGS += \

build_fila_USRLIBDIRS += \
-L$(HOME)/build/fila/lib \

build_fila_LIBS += \
-lfila \

build_fila_FRAMEWORKS += \

else
#
# build fila
#
build_fila_USRDEFINES += \

build_fila_USRINCLUDES += \

build_fila_USRCXXFLAGS += \

build_fila_USRLIBDIRS += \

build_fila_LIBS += \

build_fila_FRAMEWORKS += \

endif

########################################################################
# rete
#
# pkg-config --cflags --libs rete
#

ifndef USE_HOME_BUILD_rete
USE_HOME_BUILD_rete = no
endif

ifeq ($(USE_HOME_BUILD_rete),yes)
#
# home build rete
#
build_rete_USRDEFINES += \

build_rete_USRINCLUDES += \
-I$(HOME)/build/rete/include \

build_rete_USRCXXFLAGS += \

build_rete_USRLIBDIRS += \
-L$(HOME)/build/rete/lib \

build_rete_LIBS += \
-lrete \

build_rete_FRAMEWORKS += \

else
#
# build rete
#
build_rete_USRDEFINES += \

build_rete_USRINCLUDES += \

build_rete_USRCXXFLAGS += \

build_rete_USRLIBDIRS += \

build_rete_LIBS += \

build_rete_FRAMEWORKS += \

endif

########################################################################
# stara

# build stara USRDEFINES
#
build_stara_USRDEFINES += \
${build_rostra_USRDEFINES} \
${build_nadir_USRDEFINES} \
${build_patrona_USRDEFINES} \
${build_crono_USRDEFINES} \
${build_fila_USRDEFINES} \
${build_rete_USRDEFINES} \


# build stara USRINCLUDES
#
build_stara_USRINCLUDES += \
${build_rete_USRINCLUDES} \
${build_fila_USRINCLUDES} \
${build_crono_USRINCLUDES} \
${build_patrona_USRINCLUDES} \
${build_nadir_USRINCLUDES} \
${build_rostra_USRINCLUDES} \


# build stara USRCXXFLAGS
#
build_stara_USRCXXFLAGS += \
${build_rostra_USRCXXFLAGS} \
${build_nadir_USRCXXFLAGS} \
${build_patrona_USRCXXFLAGS} \
${build_crono_USRCXXFLAGS} \
${build_fila_USRCXXFLAGS} \
${build_rete_USRCXXFLAGS} \


# build stara USRLIBDIRS
#
build_stara_USRLIBDIRS += \
${build_rete_USRLIBDIRS} \
${build_fila_USRLIBDIRS} \
${build_crono_USRLIBDIRS} \
${build_patrona_USRLIBDIRS} \
${build_nadir_USRLIBDIRS} \
${build_rostra_USRLIBDIRS} \


# build stara FRAMEWORKS
#
build_stara_FRAMEWORKS += \
${build_rete_FRAMEWORKS} \
${build_fila_FRAMEWORKS} \
${build_crono_FRAMEWORKS} \
${build_patrona_FRAMEWORKS} \
${build_nadir_FRAMEWORKS} \
${build_rostra_FRAMEWORKS} \


# build stara LIBS
#
build_stara_LIBS += \
${build_rete_LIBS} \
${build_fila_LIBS} \
${build_crono_LIBS} \
${build_patrona_LIBS} \
${build_nadir_LIBS} \
${build_rostra_LIBS} \
${build_stara_FRAMEWORKS}


