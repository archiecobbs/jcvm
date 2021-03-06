
/*
 * @COPYRIGHT@
 *
 * $Id: java_lang_VMCompiler.c,v 1.3 2005/11/09 18:14:22 archiecobbs Exp $
 */

#include "libjc.h"
#include "java_lang_VMCompiler.h"

/*
 * public static final native boolean compileClass(Class)
 */
jboolean _JC_JCNI_ATTR
JCNI_java_lang_VMCompiler_compileClass(_jc_env *env, _jc_object *cl)
{
	_jc_jvm *const vm = env->vm;
	_jc_type *type;

	/* Check for null */
	if (cl == NULL) {
		_jc_post_exception(env, _JC_NullPointerException);
		_jc_throw_exception(env);
	}

	/* Get type */
	type = *_JC_VMFIELD(vm, cl, Class, vmdata, _jc_type *);
	_JC_ASSERT(type != NULL);

	/* Generate ELF object */
	if (_jc_generate_object(env, type->loader, type->name) != JNI_OK)
		_jc_throw_exception(env);
	return JNI_TRUE;
}

/*
 * public static final native boolean compileClasses(String)
 */
jboolean _JC_JCNI_ATTR
JCNI_java_lang_VMCompiler_compileClasses(_jc_env *env, _jc_object *string)
{
	_jc_jvm *const vm = env->vm;
	size_t slen;
	char *name;

	/* Decode string */
	slen = _jc_decode_string_utf8(env, string, NULL);
	if ((name = _JC_STACK_ALLOC(env, slen + 1)) == NULL) {
		_jc_post_exception_info(env);
		_jc_throw_exception(env);
	}
	_jc_decode_string_utf8(env, string, name);

	/* XXX we are supposed to do some kind of pattern matching... */

	/* Generate ELF object */
	if (_jc_generate_object(env, vm->boot.loader, name) != JNI_OK)
		_jc_throw_exception(env);
	return JNI_TRUE;
}

/*
 * public static final native void disable()
 */
void _JC_JCNI_ATTR
JCNI_java_lang_VMCompiler_disable(_jc_env *env)
{
	env->vm->compiler_disabled = JNI_TRUE;
}

/*
 * public static final native void enable()
 */
void _JC_JCNI_ATTR
JCNI_java_lang_VMCompiler_enable(_jc_env *env)
{
	env->vm->compiler_disabled = JNI_FALSE;
}

