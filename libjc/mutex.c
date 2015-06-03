
/*
 * @COPYRIGHT@
 *
 * $Id: mutex.c,v 1.2 2004/07/05 21:03:27 archiecobbs Exp $
 */

#include "libjc.h"

/*
 * Initialize a mutex
 *
 * If unsuccessful an exception is stored.
 */
jint
_jc_mutex_init(_jc_env *env, pthread_mutex_t *mutex)
{
	pthread_mutexattr_t attr;
	int error;

	/* Initialize mutex attributes */
	if ((error = pthread_mutexattr_init(&attr)) != 0) {
		_JC_EX_STORE(env, InternalError,
		    "%s: %s", "pthread_mutexattr_init", strerror(error));
		return JNI_ERR;
	}

#if NDEBUG
	/* Enable debug checks */
	if ((error = pthread_mutexattr_settype(&attr,
	    PTHREAD_MUTEX_ERRORCHECK)) != 0) {
		_JC_EX_STORE(env, InternalError,
		    "%s: %s", "pthread_mutexattr_settype", strerror(error));
		pthread_mutexattr_destroy(&attr);
		return JNI_ERR;
	}
#endif

	/* Initialize mutex */
	if ((error = pthread_mutex_init(mutex, &attr)) != 0) {
		_JC_EX_STORE(env, InternalError,
		    "%s: %s", "pthread_mutex_init", strerror(error));
		pthread_mutexattr_destroy(&attr);
		return JNI_ERR;
	}

	/* Clean up */
	pthread_mutexattr_destroy(&attr);
	return JNI_OK;
}

/*
 * Destroy a mutex
 */
void
_jc_mutex_destroy(pthread_mutex_t *mutex)
{
	int r;

	r = pthread_mutex_destroy(mutex);
	_JC_ASSERT(r == 0);
}

/*
 * Initialize a condition variable.
 *
 * If unsuccessful an exception is stored.
 */
jint
_jc_cond_init(_jc_env *env, pthread_cond_t *cond)
{
	int error;

	/* Initialize mutex attributes */
	if ((error = pthread_cond_init(cond, NULL)) != 0) {
		_JC_EX_STORE(env, InternalError,
		    "%s: %s", "pthread_cond_init", strerror(error));
		return JNI_ERR;
	}

	/* Done */
	return JNI_OK;
}

/*
 * Destroy a condition variable.
 */
void
_jc_cond_destroy(pthread_cond_t *cond)
{
	int r;

	r = pthread_cond_destroy(cond);
	_JC_ASSERT(r == 0);
}

