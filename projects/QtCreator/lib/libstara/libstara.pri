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
#   File: libstara.pri
#
# Author: $author$
#   Date: 12/31/2018
#
# QtCreator .pri file for stara library libstara
########################################################################

########################################################################
# libstara

# libstara TARGET
#
libstara_TARGET = stara
libstara_TEMPLATE = lib
libstara_CONFIG += staticlib

# libstara INCLUDEPATH
#
libstara_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# libstara DEFINES
#
libstara_DEFINES += \
$${stara_DEFINES} \

########################################################################
# libstara OBJECTIVE_HEADERS
#
#libstara_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# libstara OBJECTIVE_SOURCES
#
#libstara_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# libstara HEADERS
#
libstara_HEADERS += \
$${STARA_SRC}/stara/base/Base.hpp\
\
$${STARA_SRC}/stara/protocol/xttp/response/Message.hpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Line.hpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Reason.hpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Code.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Message.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Line.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Method.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Parameters.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Parts.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Fields.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/FieldsSignals.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Field.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Line.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/Part.hpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Identifier.hpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Name.hpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Version.hpp \
$${STARA_SRC}/stara/protocol/xttp/Xttp.hpp \
\
$${STARA_SRC}/stara/lib/Version.hpp \
$${STARA_SRC}/stara/lib/stara/Version.hpp \

# libstara SOURCES
#
libstara_SOURCES += \
$${STARA_SRC}/stara/base/Base.cpp\
\
$${STARA_SRC}/stara/protocol/xttp/response/Message.cpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Line.cpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Reason.cpp \
$${STARA_SRC}/stara/protocol/xttp/response/status/Code.cpp \
$${STARA_SRC}/stara/protocol/xttp/request/Method.cpp \
$${STARA_SRC}/stara/protocol/xttp/request/Parameters.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/Parts.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Fields.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/FieldsSignals.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Field.cpp \
$${STARA_SRC}/stara/protocol/xttp/message/Part.cpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Identifier.cpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Name.cpp \
$${STARA_SRC}/stara/protocol/xttp/protocol/Version.cpp \
$${STARA_SRC}/stara/protocol/xttp/Xttp.cpp \
\
$${STARA_SRC}/stara/lib/stara/Version.cpp \

########################################################################
