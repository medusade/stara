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
#   File: odbc.pro
#
# Author: $author$
#   Date: 3/4/2017
########################################################################
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/fila.pri)
include(../../fila.pri)
include(../../../../QtCreator/etiris.pri)
include(../../etiris.pri)
include(../../../../QtCreator/app/odbc/odbc.pri)

TARGET = $${odbc_TARGET}

########################################################################
INCLUDEPATH += \
$${odbc_INCLUDEPATH} \

DEFINES += \
$${odbc_DEFINES} \

########################################################################
HEADERS += \
$${odbc_HEADERS} \

SOURCES += \
$${odbc_SOURCES} \

########################################################################
LIBS += \
$${odbc_LIBS} \

