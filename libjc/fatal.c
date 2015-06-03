
/*
 * @COPYRIGHT@
 *
 * $Id: fatal.c,v 1.1.1.1 2004/02/20 05:15:34 archiecobbs Exp $
 */

#include "libjc.h"

void
_jc_fatal_error(_jc_jvm *vm, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	_jc_fatal_error_v(vm, fmt, args);
	/* va_end(args); */
}

void
_jc_fatal_error_v(_jc_jvm *vm, const char *fmt, va_list args)
{
	int (*printer)(FILE *, const char *, va_list);
	void (*aborter)(void);

	/* Print message */
	if (vm != NULL) {
		printer = vm->vfprintf;
		aborter = vm->abort;
	} else {
		printer = vfprintf;
		aborter = abort;
	}
	(*printer)(stderr, "jc: ", args);
	(*printer)(stderr, fmt, args);
	(*printer)(stderr, "\n", args);

	/* Die */
	(*aborter)();

	/* Should never get here */
	fprintf(stderr, "jc: abort() function returned!\n");
	abort();
}

