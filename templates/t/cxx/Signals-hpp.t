%########################################################################
%# Copyright (c) 1988-2017 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: Signals-hpp.t
%#
%# Author: $author$
%#   Date: 3/10/2017
%########################################################################
%with(%
%what,%(%else-then(%what%,%(What)%)%)%,%
%What,%(%else-then(%What%,%(%what%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_What%,%(%tolower(%What%)%)%)%)%,%
%which,%(%else-then(%which%,%(Which)%)%)%,%
%Which,%(%else-then(%Which%,%(%which%)%)%)%,%
%WHICH,%(%else-then(%WHICH%,%(%toupper(%Which%)%)%)%)%,%
%which,%(%else-then(%_Which%,%(%tolower(%Which%)%)%)%)%,%
%who,%(%else-then(%who%,%(Who)%)%)%,%
%Who,%(%else-then(%Who%,%(%who%)%)%)%,%
%WHO,%(%else-then(%WHO%,%(%toupper(%Who%)%)%)%)%,%
%who,%(%else-then(%_Who%,%(%tolower(%Who%)%)%)%)%,%
%do,%(%else-then(%do%,%(Do)%)%)%,%
%Do,%(%else-then(%Do%,%(%do%)%)%)%,%
%DO,%(%else-then(%DO%,%(%toupper(%Do%)%)%)%)%,%
%do,%(%else-then(%_Do%,%(%tolower(%Do%)%)%)%)%,%
%on,%(%else-then(%on%,%(On)%)%)%,%
%On,%(%else-then(%On%,%(%on%)%)%)%,%
%ON,%(%else-then(%ON%,%(%toupper(%On%)%)%)%)%,%
%on,%(%else-then(%_On%,%(%tolower(%On%)%)%)%)%,%
%signal,%(%else-then(%signal%,%(Signal)%)%)%,%
%Signal,%(%else-then(%Signal%,%(%signal%)%)%)%,%
%SIGNAL,%(%else-then(%SIGNAL%,%(%toupper(%Signal%)%)%)%)%,%
%signal,%(%else-then(%_Signal%,%(%tolower(%Signal%)%)%)%)%,%
%%(    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
%parse(%Which%,%(, )%,,,,%(%
%    virtual void %On%%Who%%What%%Signal%%Do%%Which%%(()%%())% {
        %What%%Signal%sT* signalsForwardTo = 0;
        if %(()%%(()%signalsForwardTo = this->%Who%%What%%Signal%sForwardTo%(()%%())%%())%%())% {
            signalsForwardTo->%On%%Who%%What%%Signal%%Do%%Which%%(()%%())%;
        }
        this->%On%%Who%%What%%Signal%%Do%Default%(()%%())%;
    }
%
%)%,Which)%
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void %On%%Who%%What%%Signal%%Do%Which%(()%const WhichOf& which%())% {
        %What%%Signal%sT* signalsForwardTo = 0;
        if %(()%%(()%signalsForwardTo = this->%Who%%What%%Signal%sForwardTo%(()%%())%%())%%())% {
            signalsForwardTo->%On%%Who%%What%%Signal%%Do%Which%(()%which%())%;
        }
        switch %(()%which%())% {%parse(%Which%,%(, )%,,,,%(
        case %Which%:
            this->%On%%Who%%What%%Signal%%Do%%Which%%(()%%())%;
            break;)%,Which)%
        default:
            this->%On%%Who%%What%%Signal%%Do%Default%(()%%())%;
            break;
        }
    }
%
%)%)%