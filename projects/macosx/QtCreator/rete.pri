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
#   File: rete.pri
#
# Author: $author$
#   Date: 12/12/2016
########################################################################

########################################################################
# rete
RETE_BLD = ../$${RETE_PKG}/build/$${STARA_OS}/QtCreator/$${RETE_CONFIG}
RETE_LIB = $${RETE_BLD}/lib

rete_INCLUDEPATH += \

rete_DEFINES += \

rete_LIBS += \
-L$${RETE_LIB}/librete \
-lrete \
