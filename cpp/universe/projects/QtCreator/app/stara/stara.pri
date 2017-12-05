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
#   Date: 12/2/2017
#
# QtCreator .pri file for stara executable stara
########################################################################

stara_exe_TARGET = stara

########################################################################
stara_exe_INCLUDEPATH += \
$${stara_INCLUDEPATH} \
$${libnavajo_INCLUDEPATH} \

stara_exe_DEFINES += \
$${stara_DEFINES} \
$${libnavajo_DEFINES} \

########################################################################
# stara
stara_exe_HEADERS += \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/WebServer.h \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/WebRepository.h \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/WebSignals.h \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/Main.h \
$${STARA_SRC}/universe/console/Main.h \
$${STARA_SRC}/universe/console/Logger.h \
$${STARA_SRC}/universe/console/Io.h \
$${STARA_SRC}/universe/logger/Interface.h \
$${STARA_SRC}/universe/logger/Output.h \
$${STARA_SRC}/universe/logger/Stdio.h \
$${STARA_SRC}/universe/logger/Message.h \
$${STARA_SRC}/universe/logger/Enabled.h \
$${STARA_SRC}/universe/logger/Level.h \
$${STARA_SRC}/universe/mt/posix/Mutex.h \
$${STARA_SRC}/universe/mt/Mutex.h \
$${STARA_SRC}/universe/base/Opened.h \
$${STARA_SRC}/universe/base/Created.h \
$${STARA_SRC}/universe/base/Attached.h \
$${STARA_SRC}/universe/base/Base.h \

stara_exe_SOURCES += \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/WebServer.cpp \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/WebRepository.cpp \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/WebSignals.cpp \
$${STARA_SRC}/universe/protocol/http/daemon/libnavajo/Main.cpp \
$${STARA_SRC}/universe/console/Logger.cpp \
$${STARA_SRC}/universe/console/Io.cpp \
$${STARA_SRC}/universe/mt/posix/Mutex.cpp \
$${STARA_SRC}/universe/logger/Interface.cpp \
$${STARA_SRC}/universe/logger/Output.cpp \
$${STARA_SRC}/universe/logger/Message.cpp \
$${STARA_SRC}/universe/logger/Stdio.cpp \
$${STARA_SRC}/universe/logger/Enabled.cpp \
$${STARA_SRC}/universe/logger/Level.cpp \
$${STARA_SRC}/universe/base/Opened.cpp \
$${STARA_SRC}/universe/base/Created.cpp \
$${STARA_SRC}/universe/base/Attached.cpp \
$${STARA_SRC}/universe/base/Base.cpp \

########################################################################
stara_exe_LIBS += \
$${stara_LIBS} \
$${libnavajo_LIBS} \
