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
#   File: hello.pri
#
# Author: $author$
#   Date: 3/9/2017
########################################################################

hello_TARGET = stara-http-hello

########################################################################
hello_INCLUDEPATH += \
$${stara_INCLUDEPATH} \
$${rete_INCLUDEPATH} \
$${fila_INCLUDEPATH} \

hello_DEFINES += \
$${stara_DEFINES} \

########################################################################
hello_HEADERS += \
$${STARA_SRC}/stara/protocol/xttp/response/Message.hpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Line.hpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Reason.hpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Code.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Message.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Line.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Method.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/MethodSignals.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Parameters.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Parts.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Fields.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/FieldsSignals.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Field.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Line.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Part.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Which.hpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Identifier.hpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Name.hpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Version.hpp \
$${STARA_SRC}/stara/protocol/xttp/Xttp.hpp \

hello_SOURCES += \
$${STARA_SRC}/stara/protocol/xttp/response/Message.cpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Line.cpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Reason.cpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Code.cpp \
$${STARA_SRC}/stara/protocol/xttp/request/Parameters.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/Parts.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Fields.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/FieldsSignals.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Field.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/Part.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/Which.cpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Identifier.cpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Name.cpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Version.cpp \
$${STARA_SRC}/stara/protocol/xttp/Xttp.cpp \

########################################################################
hello_HEADERS += \
$${STARA_SRC}/stara/protocol/http/request/MethodSignals.hpp \
$${STARA_SRC}/stara/protocol/http/request/Method.hpp \

hello_SOURCES += \
$${STARA_SRC}/stara/protocol/http/request/Method.cpp \
$${STARA_SRC}/stara/protocol/http/request/MethodSignals.cpp \

########################################################################
hello_HEADERS += \
$${STARA_SRC}/stara/console/getopt/MainOpt.hpp \
$${STARA_SRC}/stara/console/getopt/Main.hpp \
$${STARA_SRC}/stara/console/Main.hpp \
$${STARA_SRC}/stara/console/Main_main.hpp \

hello_SOURCES += \
$${STARA_SRC}/stara/console/Main_main.cpp \

########################################################################
hello_LIBS += \
$${stara_LIBS} \
