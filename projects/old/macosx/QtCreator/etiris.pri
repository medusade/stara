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
#   File: etiris.pri
#
# Author: $author$
#   Date: 3/8/2017
########################################################################

HOME = /Users/jboyd

########################################################################
# iconv
ICONV_BLD = $${HOME}/build/libiconv
ICONV_LIB = $${ICONV_BLD}

########################################################################
# unixODBC
UNIXODBC_BLD = $${HOME}/build/unixODBC
UNIXODBC_LIB = $${UNIXODBC_BLD}/lib

unixODBC_INCLUDEPATH += \
$${UNIXODBC_BLD}/include \

unixODBC_LIBS += \
-L$${UNIXODBC_LIB} \
-lodbc \
-lodbcinst \
-L$${ICONV_LIB} \
-liconv \
-lcharset \
-lpthread \
-ldl \

########################################################################
# etiris
ETIRIS_BLD = ../$${ETIRIS_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
ETIRIS_LIB = $${ETIRIS_BLD}/lib

etiris_INCLUDEPATH += \
$${unixODBC_INCLUDEPATH} \

etiris_LIBS += \
$${unixODBC_LIBS} \
