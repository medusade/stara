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
#   File: libstara.pri
#
# Author: $author$
#   Date: 9/15/2017
#
# QtCreator .pri file for stara library libstara
########################################################################

libstara_TARGET = stara

########################################################################
libstara_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

libstara_DEFINES += \
$${stara_DEFINES} \

########################################################################
# nadir
libstara_HEADERS += \
$${NADIR_SRC}/xos/io/Reader.hpp \

libstara_SOURCES += \
$${NADIR_SRC}/xos/io/Reader.cpp \

########################################################################
# stara
#libstara_HEADERS += \
#$${STARA_SRC}/xos/base/Base.hpp \

#libstara_SOURCES += \
#$${STARA_SRC}/xos/base/Base.cpp \

########################################################################



