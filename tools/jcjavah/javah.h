
/*
 * @COPYRIGHT@
 *
 * $Id: javah.h,v 1.1 2005/01/08 23:25:06 archiecobbs Exp $
 */

#ifndef _JAVAH_H_
#define _JAVAH_H_

#include "libjc.h"
#include <sys/param.h>
#include <err.h>
#include <assert.h>

#define EXCEPTION_MSG_MAX	128

extern int	exception;
extern char	exception_msg[EXCEPTION_MSG_MAX];

extern _jc_env		*_jc_support_init(void);

extern void		javah_header(_jc_classfile *cfile,
				const char *dir, jboolean jni);
extern void		javah_source(_jc_classfile *cfile,
				const char *dir, jboolean jni);
extern _jc_classbytes	*read_classbytes(_jc_env *env,
				const char *dir, const char *name);

#endif	/* _JAVAH_H_ */
