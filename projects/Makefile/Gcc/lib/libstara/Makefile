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
# generic Gcc Makefile for stara Library libstara
########################################################################


#
# target
#
libstara_LIBTARGET = libstara.${LIBEXT}

########################################################################

#
# user c++ flags
#
libstara_USRCXXFLAGS += \
${stara_USRCXXFLAGS} \

#
# user defines
#
libstara_USRDEFINES += \
${stara_USRDEFINES} \

#
# user includes
#
libstara_USRINCLUDES += \
${stara_USRINCLUDES} \

#
# user libdirs
#
libstara_USRLIBDIRS += \
${stara_USRLIBDIRS} \

########################################################################

#
# Library .c sources
#
#libstara_LIB_C_SOURCES += \
#${STARA_SRC}/stara/base/Base.c \

#
# Library .cc sources
#
#libstara_LIB_CC_SOURCES += \
#${STARA_SRC}/stara/base/Base.cc \

#
# Library .cxx sources
#
#libstara_LIB_CXX_SOURCES += \
#${STARA_SRC}/stara/base/Base.cxx \

#
# Library .cpp sources
#
libstara_LIB_CPP_SOURCES += \
${STARA_SRC}/stara/base/Base.cpp\
\
${STARA_SRC}/stara/protocol/xttp/response/Message.cpp \
${STARA_SRC}/stara/protocol/xttp/response/status/Line.cpp \
${STARA_SRC}/stara/protocol/xttp/response/status/Reason.cpp \
${STARA_SRC}/stara/protocol/xttp/response/status/Code.cpp \
${STARA_SRC}/stara/protocol/xttp/request/Method.cpp \
${STARA_SRC}/stara/protocol/xttp/request/Parameters.cpp \
${STARA_SRC}/stara/protocol/xttp/message/Parts.cpp \
${STARA_SRC}/stara/protocol/xttp/message/header/Fields.cpp \
${STARA_SRC}/stara/protocol/xttp/message/header/FieldsSignals.cpp \
${STARA_SRC}/stara/protocol/xttp/message/header/Field.cpp \
${STARA_SRC}/stara/protocol/xttp/message/Part.cpp \
${STARA_SRC}/stara/protocol/xttp/protocol/Identifier.cpp \
${STARA_SRC}/stara/protocol/xttp/protocol/Name.cpp \
${STARA_SRC}/stara/protocol/xttp/protocol/Version.cpp \
${STARA_SRC}/stara/protocol/xttp/Xttp.cpp \
\
${STARA_SRC}/stara/lib/stara/Version.cpp \

#
# Library .m sources
#
#libstara_LIB_M_SOURCES += \
#${STARA_SRC}/stara/base/Base.m \

#
# Library .mm sources
#
#libstara_LIB_MM_SOURCES += \
#${STARA_SRC}/stara/base/Base.mm \


########################################################################




