
/*
 * @COPYRIGHT@
 *
 * $Id: support.c,v 1.5 2005/11/23 17:54:40 archiecobbs Exp $
 */

#include "cfdump.h"

static _jc_class_loader	phoney_loader;
static _jc_env		phoney_env;
static _jc_jvm		phoney_jvm;

jboolean
_jc_interp_z(_jc_env *env, ...)
{
	return 0;
}

jbyte
_jc_interp_b(_jc_env *env, ...)
{
	return 0;
}

jchar
_jc_interp_c(_jc_env *env, ...)
{
	return 0;
}

jshort
_jc_interp_s(_jc_env *env, ...)
{
	return 0;
}

jint
_jc_interp_i(_jc_env *env, ...)
{
	return 0;
}

jlong
_jc_interp_j(_jc_env *env, ...)
{
	return 0;
}

jfloat
_jc_interp_f(_jc_env *env, ...)
{
	return 0;
}

jdouble
_jc_interp_d(_jc_env *env, ...)
{
	return 0;
}

_jc_object *
_jc_interp_l(_jc_env *env, ...)
{
	return NULL;
}

void
_jc_interp_v(_jc_env *env, ...)
{
}

jboolean
_jc_interp_native_z(_jc_env *env, ...)
{
	return 0;
}

jbyte
_jc_interp_native_b(_jc_env *env, ...)
{
	return 0;
}

jchar
_jc_interp_native_c(_jc_env *env, ...)
{
	return 0;
}

jshort
_jc_interp_native_s(_jc_env *env, ...)
{
	return 0;
}

jint
_jc_interp_native_i(_jc_env *env, ...)
{
	return 0;
}

jlong
_jc_interp_native_j(_jc_env *env, ...)
{
	return 0;
}

jfloat
_jc_interp_native_f(_jc_env *env, ...)
{
	return 0;
}

jdouble
_jc_interp_native_d(_jc_env *env, ...)
{
	return 0;
}

_jc_object *
_jc_interp_native_l(_jc_env *env, ...)
{
	return NULL;
}

void
_jc_interp_native_v(_jc_env *env, ...)
{
}

jint
_jc_gc(_jc_env *env, jboolean urgent)
{
	return JNI_OK;
}

_jc_env *
_jc_get_current_env()
{
	return &phoney_env;
}

_jc_env	*
_jc_support_init()
{
	_jc_mutex_init(&phoney_env, &phoney_loader.mutex);
	_jc_mutex_init(&phoney_env, &phoney_jvm.mutex);
	_jc_uni_alloc_init(&phoney_loader.uni, 0, NULL);
	phoney_jvm.boot.loader = &phoney_loader;
	phoney_env.vm = &phoney_jvm;
	return &phoney_env;
}

void
_jc_fatal_error(_jc_jvm *vm __attribute__ ((unused)), const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vwarnx(fmt, args);
	va_end(args);
	abort();
}

void
_jc_post_exception(_jc_env *env, int num)
{
	_jc_post_exception_msg(env, num, NULL);
}

void
_jc_post_exception_info(_jc_env *env)
{
	_jc_post_exception_msg(env, env->ex.num,
	    *env->ex.msg != '\0' ? env->ex.msg : NULL);
}

_jc_object *
_jc_retrieve_exception(_jc_env *env, _jc_type *type)
{
	return NULL;
}

jboolean
_jc_unpost_exception(_jc_env *env, int num)
{
	return JNI_TRUE;
}

void
_jc_post_exception_msg(_jc_env *env __attribute__ ((unused)),
	int num, const char *fmt, ...)
{
	assert(0);
}

void
_jc_loader_wait(_jc_env *env, _jc_class_loader *loader)
{
}

