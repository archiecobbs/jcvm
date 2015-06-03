
/*
 * @COPYRIGHT@
 *
 * $Id: jc_invoke.h,v 1.1 2005/01/13 04:44:59 archiecobbs Exp $
 */

/*
 * VM printer function type.
 */
typedef int	_jc_printer(FILE *stream, const char *fmt, va_list args);

/*
 * Return values from _jc_invoke()
 */
#define _JC_RETURN_NORMAL	0		/* normal return */
#define _JC_RETURN_EXCEPTION	1		/* exception thrown */
#define _JC_RETURN_ERROR	2		/* error during startup */

/*
 * Invoke the JC Java virtual machine.
 */
extern int	_jc_invoke(int ac, const char **av,
			int ignoreUnrecognized, _jc_printer *printer);

