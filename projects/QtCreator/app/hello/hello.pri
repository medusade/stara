########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   Date: 12/12/2016
########################################################################

hello_INCLUDEPATH += \
$${stara_INCLUDEPATH} \
$${rete_INCLUDEPATH} \
$${fila_INCLUDEPATH} \

hello_DEFINES += \
$${stara_DEFINES} \

########################################################################
hello_HEADERS += \

hello_SOURCES += \

########################################################################
hello_HEADERS += \

hello_SOURCES += \

########################################################################
hello_HEADERS += \

hello_SOURCES += \

########################################################################
hello_HEADERS += \

hello_SOURCES += \

########################################################################
hello_HEADERS += \
$${RETE_SRC}/rete/network/SocketStream.hpp \
$${RETE_SRC}/rete/network/SocketWriter.hpp \
$${RETE_SRC}/rete/network/SocketReader.hpp \
$${RETE_SRC}/rete/io/Stream.hpp \
$${RETE_SRC}/rete/io/Writer.hpp \
$${RETE_SRC}/rete/io/Reader.hpp \

hello_SOURCES += \
$${RETE_SRC}/rete/network/SocketStream.cpp \
$${RETE_SRC}/rete/network/SocketWriter.cpp \
$${RETE_SRC}/rete/network/SocketReader.cpp \

########################################################################
hello_HEADERS += \
$${STARA_SRC}/stara/console/getopt/MainOpt.hpp \
$${STARA_SRC}/stara/console/getopt/Main.hpp \
$${STARA_SRC}/stara/console/Main.hpp \
$${STARA_SRC}/stara/console/Main_main.hpp \
$${STARA_SRC}/stara/app/console/hello/MainOpt.hpp \
$${STARA_SRC}/stara/app/console/hello/Main.hpp \

hello_SOURCES += \
$${STARA_SRC}/stara/app/console/hello/Main.cpp \

########################################################################
hello_LIBS += \
$${stara_LIBS} \
