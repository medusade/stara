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
#   File: hello.pro
#
# Author: $author$
#   Date: 3/9/2017
########################################################################
STARA_PRO_DIR = ../../
include($${STARA_PRO_DIR}../../../../QtCreator/stara.pri)
include($${STARA_PRO_DIR}../../stara.pri)
include($${STARA_PRO_DIR}../../../../QtCreator/rete.pri)
include($${STARA_PRO_DIR}../../rete.pri)
include($${STARA_PRO_DIR}../../../../QtCreator/fila.pri)
include($${STARA_PRO_DIR}../../fila.pri)
include($${STARA_PRO_DIR}../../../../QtCreator/app/protocol/http/hello/hello.pri)

TARGET = $${hello_TARGET}

########################################################################
INCLUDEPATH += \
$${hello_INCLUDEPATH} \

DEFINES += \
$${hello_DEFINES} \

########################################################################
HEADERS += \
$${hello_HEADERS} \

SOURCES += \
$${hello_SOURCES} \

########################################################################
LIBS += \
$${hello_LIBS} \

