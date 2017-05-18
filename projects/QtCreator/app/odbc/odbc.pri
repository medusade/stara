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
#   File: odbc.pri
#
# Author: $author$
#   Date: 3/4/2017
########################################################################

odbc_TARGET = stara-odbc

########################################################################
odbc_INCLUDEPATH += \
$${stara_INCLUDEPATH} \
$${rete_INCLUDEPATH} \
$${fila_INCLUDEPATH} \
$${etiris_INCLUDEPATH} \

odbc_DEFINES += \
$${stara_DEFINES} \
$${etiris_DEFINES} \

########################################################################
odbc_HEADERS += \
$${NADIR_SRC}/nadir/console/io.hpp \

odbc_SOURCES += \
$${NADIR_SRC}/nadir/console/io.cpp \

########################################################################
odbc_HEADERS += \
$${STARA_SRC}/stara/io/Stream.hpp \
$${STARA_SRC}/stara/io/Writer.hpp \
$${STARA_SRC}/stara/io/Reader.hpp \
$${STARA_SRC}/stara/base/Base.hpp \

########################################################################
odbc_HEADERS += \
$${STARA_SRC}/stara/protocol/xttp/message/body/Reader.hpp \
$${STARA_SRC}/stara/protocol/xttp/message/header/Fields.hpp \
$${STARA_SRC}/stara/protocol/xttp/request/Line.hpp \

odbc_SOURCES += \
$${STARA_SRC}/stara/protocol/xttp/message/body/Reader.cpp \
$${STARA_SRC}/stara/protocol/xttp/request/Line.cpp \

########################################################################
odbc_HEADERS += \
$${STARA_SRC}/stara/protocol/http/url/encoded/form/Fields.hpp \
$${STARA_SRC}/stara/protocol/http/url/encoded/form/ContentType.hpp \
$${STARA_SRC}/stara/protocol/http/url/encoded/Reader.hpp \
$${STARA_SRC}/stara/protocol/http/request/Method.hpp \
$${STARA_SRC}/stara/protocol/http/form/Fields.hpp \
$${STARA_SRC}/stara/protocol/http/form/FieldsSignals.hpp \
$${STARA_SRC}/stara/protocol/http/form/Field.hpp \

odbc_SOURCES += \
$${STARA_SRC}/stara/protocol/http/url/encoded/form/Fields.cpp \
$${STARA_SRC}/stara/protocol/http/url/encoded/form/ContentType.cpp \
$${STARA_SRC}/stara/protocol/http/url/encoded/Reader.cpp \
$${STARA_SRC}/stara/protocol/http/request/Method.cpp \
$${STARA_SRC}/stara/protocol/http/form/FieldsSignals.cpp \
$${STARA_SRC}/stara/protocol/http/form/Field.cpp \

########################################################################
odbc_HEADERS += \
$${STARA_SRC}/stara/console/getopt/MainOpt.hpp \
$${STARA_SRC}/stara/console/getopt/Main.hpp \
$${STARA_SRC}/stara/console/Main.hpp \
$${STARA_SRC}/stara/console/Main_main.hpp \

odbc_SOURCES += \

########################################################################
odbc_HEADERS += \
$${STARA_SRC}/stara/app/console/connected/http/odbc/Main.hpp \
$${STARA_SRC}/stara/app/console/connected/http/odbc/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/connected/http/Main.hpp \
$${STARA_SRC}/stara/app/console/connected/http/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/connected/Main.hpp \
$${STARA_SRC}/stara/app/console/connected/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/Main.hpp \
$${STARA_SRC}/stara/app/console/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/Main_main.hpp \

odbc_SOURCES += \
$${STARA_SRC}/stara/app/console/connected/http/odbc/Main.cpp \
$${STARA_SRC}/stara/app/console/connected/http/odbc/MainOpt.cpp \
$${STARA_SRC}/stara/app/console/Main_main.cpp \

########################################################################
odbc_LIBS += \
$${stara_LIBS} \
$${etiris_LIBS} \


