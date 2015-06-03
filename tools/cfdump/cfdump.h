
/*
 * @COPYRIGHT@
 *
 * $Id: cfdump.h,v 1.2 2004/07/05 21:03:29 archiecobbs Exp $
 */

#ifndef _CFDUMP_H_
#define _CFDUMP_H_

#include "libjc.h"
#include <err.h>
#include <assert.h>

/* Flags */
#define DUMP_ENCODE_NAMES	0x0001
#define DUMP_TRANS_CLOSURE	0x0002
#define DUMP_SUPERS_ONLY	0x0004

extern void	do_deps(_jc_env *env, _jc_classfile *cf, int flags);
extern _jc_env	*_jc_support_init(void);

#endif	/* _CFDUMP_H_ */
