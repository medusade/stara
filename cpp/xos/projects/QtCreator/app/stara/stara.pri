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
#   Date: 9/15/2017
#
# QtCreator .pri file for stara executable stara
########################################################################

stara_exe_TARGET = stara

########################################################################
stara_exe_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

stara_exe_DEFINES += \
$${stara_DEFINES} \
XOS_APP_CONSOLE_STARA_THE_MAIN \

########################################################################
# nadir
stara_exe_HEADERS += \
$${NADIR_SRC}/xos/io/Stream.hpp \
$${NADIR_SRC}/xos/io/Writer.hpp \
$${NADIR_SRC}/xos/io/Reader.hpp \
$${NADIR_SRC}/xos/base/String.hpp \

stara_exe_SOURCES += \
$${NADIR_SRC}/xos/io/Stream.cpp \
$${NADIR_SRC}/xos/io/Writer.cpp \
$${NADIR_SRC}/xos/io/Reader.cpp \
$${NADIR_SRC}/xos/base/String.cpp \

########################################################################
# fila
stara_exe_HEADERS += \
$${FILA_SRC}/xos/console/mt/Main_main.hpp \

stara_exe_SOURCES += \
$${FILA_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
# rete
stara_exe_HEADERS += \
$${RETE_SRC}/xos/network/InterfaceWriter.hpp \
$${RETE_SRC}/xos/network/InterfaceReader.hpp \

stara_exe_SOURCES += \
$${RETE_SRC}/xos/network/InterfaceWriter.cpp \
$${RETE_SRC}/xos/network/InterfaceReader.cpp \

########################################################################
# stara
stara_exe_HEADERS += \
$${STARA_SRC}/xos/protocol/xttp/response/Message.hpp \
$${STARA_SRC}/xos/protocol/xttp/response/status/Line.hpp \
$${STARA_SRC}/xos/protocol/xttp/response/status/Reason.hpp \
$${STARA_SRC}/xos/protocol/xttp/response/status/Code.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/Message.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/Line.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/Parameters.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/Method.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/MethodSignals.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/Parts.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/Fields.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/FieldsSignals.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/Field.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/Line.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/Part.hpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/Identifier.hpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/Version.hpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/Name.hpp \
$${STARA_SRC}/xos/protocol/xttp/Xttp.hpp \

stara_exe_SOURCES += \
$${STARA_SRC}/xos/protocol/xttp/response/Message.cpp \
$${STARA_SRC}/xos/protocol/xttp/response/status/Line.cpp \
$${STARA_SRC}/xos/protocol/xttp/response/status/Reason.cpp \
$${STARA_SRC}/xos/protocol/xttp/response/status/Code.cpp \
$${STARA_SRC}/xos/protocol/xttp/request/Parameters.cpp \
$${STARA_SRC}/xos/protocol/xttp/request/Method.cpp \
$${STARA_SRC}/xos/protocol/xttp/request/MethodSignals.cpp \
$${STARA_SRC}/xos/protocol/xttp/message/Parts.cpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/Fields.cpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/FieldsSignals.cpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/Field.cpp \
$${STARA_SRC}/xos/protocol/xttp/message/Part.cpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/Identifier.cpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/Version.cpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/Name.cpp \
$${STARA_SRC}/xos/protocol/xttp/Xttp.cpp \

########################################################################
# stara
stara_exe_HEADERS += \
$${STARA_SRC}/xos/app/console/stara/Main.hpp \
$${STARA_SRC}/xos/app/console/stara/MainOpt.hpp \

stara_exe_SOURCES += \
$${STARA_SRC}/xos/app/console/stara/Main.cpp \
$${STARA_SRC}/xos/app/console/stara/MainOpt.cpp \

########################################################################
stara_exe_LIBS += \
$${stara_LIBS} \


