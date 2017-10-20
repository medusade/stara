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
#   File: Makefile
#
# Author: $author$
#   Date: 10/11/2017
#
# generic Gcc Makefile for stara Executable stara
########################################################################


#
# target
#
stara_exe_EXETARGET = stara

########################################################################

#
# user c++ flags
#
stara_exe_USRCXXFLAGS += \
${stara_USRCXXFLAGS} \

#
# user defines
#
stara_exe_USRDEFINES += \
${stara_USRDEFINES} \
-DXOS_APP_CONSOLE_STARA_THE_MAIN \

#
# user includes
#
stara_exe_USRINCLUDES += \
${stara_USRINCLUDES} \

#
# user libdirs
#
stara_exe_USRLIBDIRS += \
${stara_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#stara_exe_EXE_C_SOURCES += \
#${STARA_SRC}/stara/base/Base.c \

#
# Executable .cc sources
#
#stara_exe_EXE_CC_SOURCES += \
#${STARA_SRC}/stara/base/Base.cc \

#
# Executable .cxx sources
#
#stara_exe_EXE_CXX_SOURCES += \
#${STARA_SRC}/stara/base/Base.cxx \

#
# Executable .cpp sources
#
stara_exe_EXE_CPP_SOURCES += \
${STARA_SRC}/xos/app/console/stara/Main.cpp \
${STARA_SRC}/xos/app/console/stara/MainOpt.cpp \
${FILA_SRC}/xos/console/mt/Main_main.cpp \

#
# Executable .m sources
#
#stara_exe_EXE_M_SOURCES += \
#${STARA_SRC}/stara/base/Base.m \

#
# Executable .mm sources
#
#stara_exe_EXE_MM_SOURCES += \
#${STARA_SRC}/stara/base/Base.mm \


########################################################################

#
# Executable libraries
#
stara_exe_LIBS += \
${stara_LIBS}



