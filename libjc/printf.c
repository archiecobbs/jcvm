
/*
 * @COPYRIGHT@
 *
 * $Id: printf.c,v 1.2 2004/07/18 02:19:12 archiecobbs Exp $
 */

#include "libjc.h"

/*
 * Print something to standard output.
 */
int
_jc_printf(_jc_jvm *vm, const char *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = (vm != NULL) ?
	    (*vm->vfprintf)(stdout, fmt, args) :
	    vfprintf(stdout, fmt, args);
	va_end(args);
	return r;
}

/*
 * Print something to standard error.
 */
int
_jc_eprintf(_jc_jvm *vm, const char *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = (vm != NULL) ?
	    (*vm->vfprintf)(stderr, fmt, args) :
	    vfprintf(stderr, fmt, args);
	va_end(args);
	return r;
}

/*
 * Print something to wherever.
 */
int
_jc_fprintf(_jc_jvm *vm, FILE *fp, const char *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = (vm != NULL) ?
	    (*vm->vfprintf)(fp, fmt, args) :
	    vfprintf(fp, fmt, args);
	va_end(args);
	return r;
}

/*
 * Print out a string (e.g., class name) with dots instead of slashes.
 */
void
_jc_fprint_noslash(_jc_jvm *vm, FILE *fp, const char *s)
{
	while (*s != '\0') {
		_jc_fprintf(vm, fp, "%c", *s == '/' ? '.' : *s);
		s++;
	}
}

