/**
 **********************************************************************
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: html-form.js
 *
 * Author: $author$           
 *   Date: %date()%
 *
 * Copyright (c) %year()% $organization$     
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: getFormFieldValue
 **********************************************************************
 */
function getFormFieldValue(name, form) {
    if (!form) {
		form = 'form';
    }
    if (name) {
        if ((field = document[form][name])) {
            if ((value = field.value)) {
                return value;
            } else {
                len = field.length;
                if (0 < len) {
                    for (i = 0; i < len; i++) {
                        if (field[i].checked) {
                            if ((value = field[i].value)) {
                                return value;
                            }
                        }
                    }
                }
            }
        }
    } else {
        alert("failed on getFormFieldValue(0, '" + form + "')");
    }
	return '';
}

/**
 **********************************************************************
 * Function: getFormValue
 **********************************************************************
 */
function getFormValue(name, form) {
    if (!form) {
        form = 'form';
    }
    if (name) {
        if ((value = getFormFieldValue(name, form))) {
            return value;
        }
        alert("failed on getFormValue('" + name + "', '" + form + "')");
    } else {
        alert("failed on getFormValue(0, '" + form + "')");
    }
    return '';
}

/**
 **********************************************************************
 * Function: getFormValue2
 **********************************************************************
 */
function getFormValue2(name1, name2, form) {
    if ((value = getFormFieldValue(name1, form))) {
        return value;
    }
    if ((value = getFormValue(name2, form))) {
        return value;
    }
    return '';
}

/**
 **********************************************************************
 * Function: setFormSubmit
 **********************************************************************
 */
function setFormSubmit(action, method, form) {
    if (!form) {
        form = 'form';
    }
    if ((field = document[form])) {
        if (action) {
            if ('' != action) {
                field.action = action;
            }
        }
        if (method) {
            if ('' != method) {
                field.method = method;
            }
        }
    }
    return true;
}

/**
 **********************************************************************
 * Function: setFormSubmit2
 **********************************************************************
 */
function setFormSubmit2(action1, action2, method, form) {
    if (!form) {
        form = 'form';
    }
    if ((field = document[form])) {
        if (action1) {
            if ('' != action1) {
                field.action = action1;
            } else {
                if (action2) {
                    if ('' != action2) {
                        field.action = action2;
                    }
                }
            }
        } else {
            if (action2) {
                if ('' != action2) {
                    field.action = action2;
                }
            }
        }
        if (method) {
            if ('' != method) {
                field.method = method;
            }
        }
    }
    return true;
}
