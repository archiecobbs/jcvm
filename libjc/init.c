
/*
 * @COPYRIGHT@
 *
 * $Id: init.c,v 1.1.1.1 2004/02/20 05:15:35 archiecobbs Exp $
 */

#include "libjc.h"

/* Internal variables */
static jint	_jc_init_result = JNI_ERR;

/* Internal functions */
static void	_jc_do_init(void);

/*
 * One-time global initialization.
 */
jint
_jc_init(void)
{
	static pthread_once_t once = PTHREAD_ONCE_INIT;

	pthread_once(&once, _jc_do_init);
	return _jc_init_result;
}

static void
_jc_do_init(void)
{
	if (_jc_thread_init() != JNI_OK)
		return;
	if (_jc_init_signals() != JNI_OK)
		return;
	_jc_init_result = JNI_OK;
}

