
/*
 * @COPYRIGHT@
 *
 * $Id: gnu_classpath_VMStackWalker.c,v 1.6 2006/01/21 01:45:07 archiecobbs Exp $
 */

#include "libjc.h"
#include "gnu_classpath_VMStackWalker.h"
#include "java_lang_VMClass.h"

/* Internal functions */
static jboolean	_jc_poppable_method(_jc_jvm *vm, _jc_method *method);

static jboolean
_jc_poppable_method(_jc_jvm *vm, _jc_method *method)
{
	/* Check for VMStackWalker methods */
	if (method->class == vm->boot.types.VMStackWalker
	    && strcmp(method->name, "getClassContext") == 0)
		return JNI_TRUE;

	/* Check for Method.invoke() */
	if (method == vm->boot.methods.Method.invoke)
		return JNI_TRUE;

	/* Not poppable */
	return JNI_FALSE;
}

/*
 * public static final native Class getCallingClass()
 */
_jc_object * _JC_JCNI_ATTR
JCNI_gnu_classpath_VMStackWalker_getCallingClass(_jc_env *env)
{
	_jc_jvm *const vm = env->vm;
	_jc_object *result = NULL;
	_jc_stack_crawl crawl;
	jboolean top;

	/* Lock VM */
	_JC_MUTEX_LOCK(env, vm->mutex);

	/* Crawl up the stack */
	for (top = JNI_TRUE, _jc_stack_crawl_first(env, &crawl);
	    crawl.method != NULL; _jc_stack_crawl_next(vm, &crawl)) {

		/* Ignore non-Java stack frames */
		if (crawl.method->class == NULL)
			continue;

		/* Ignore internal methods on top of stack */
		if (top && _jc_poppable_method(vm, crawl.method))
			continue;
		top = JNI_FALSE;

		/* Pop one additional frame */
		do
		    _jc_stack_crawl_next(vm, &crawl);
		while (crawl.method != NULL && crawl.method->class == NULL);

		/* Done */
		if (crawl.method != NULL && crawl.method->class != NULL)
			result = crawl.method->class->instance;
		break;
	}

	/* Unlock VM */
	_JC_MUTEX_UNLOCK(env, vm->mutex);

	/* Done */
	return result;
}

/*
 * public static final native ClassLoader getCallingClassLoader()
 */
_jc_object * _JC_JCNI_ATTR
JCNI_gnu_classpath_VMStackWalker_getCallingClassLoader(_jc_env *env)
{
	_jc_jvm *const vm = env->vm;
	_jc_object *result = NULL;
	_jc_stack_crawl crawl;
	jboolean top;

	/* Lock VM */
	_JC_MUTEX_LOCK(env, vm->mutex);

	/* Crawl up the stack */
	for (top = JNI_TRUE, _jc_stack_crawl_first(env, &crawl);
	    crawl.method != NULL; _jc_stack_crawl_next(vm, &crawl)) {

		/* Ignore non-Java stack frames */
		if (crawl.method->class == NULL)
			continue;

		/* Ignore internal methods on top of stack */
		if (top && _jc_poppable_method(vm, crawl.method))
			continue;
		top = JNI_FALSE;

		/* Pop one additional frame */
		do
		    _jc_stack_crawl_next(vm, &crawl);
		while (crawl.method != NULL && crawl.method->class == NULL);

		/* Done */
		if (crawl.method != NULL && crawl.method->class != NULL)
			result = crawl.method->class->loader->instance;
		break;
	}

	/* Unlock VM */
	_JC_MUTEX_UNLOCK(env, vm->mutex);

	/* Done */
	return result;
}

/*
 * public static final native Class[] getClassContext()
 */
_jc_object_array * _JC_JCNI_ATTR
JCNI_gnu_classpath_VMStackWalker_getClassContext(_jc_env *env)
{
	_jc_jvm *const vm = env->vm;
	_jc_object_array *array = NULL;
	_jc_stack_crawl crawl;
	jboolean top;
	int num;

again:
	/* Lock VM */
	_JC_MUTEX_LOCK(env, vm->mutex);

	/* Crawl the Java stack and add Class objects for each method */
	for (num = 0, top = JNI_TRUE, _jc_stack_crawl_first(env, &crawl);
	    crawl.method != NULL; _jc_stack_crawl_next(vm, &crawl)) {

		/* Ignore non-Java stack frames */
		if (crawl.method->class == NULL)
			continue;

		/* Ignore internal methods on top of stack */
		if (top && _jc_poppable_method(vm, crawl.method))
			continue;
		top = JNI_FALSE;

		/* Add method's class */
		if (array != NULL)
			array->elems[~num] = crawl.method->class->instance;
		num++;
	}

	/* Unlock VM */
	_JC_MUTEX_UNLOCK(env, vm->mutex);

	/* Create array and loop back */
	if (array == NULL) {
		if ((array = (_jc_object_array *)_jc_new_array(env,
		    vm->boot.types.Class_array, num)) == NULL) {
			_JC_MUTEX_UNLOCK(env, vm->mutex);
			_jc_throw_exception(env);
		}
		goto again;
	}
	_JC_ASSERT(num == array->length);

	/* Done */
	return array;
}

_jc_object * _JC_JCNI_ATTR
JCNI_gnu_classpath_VMStackWalker_getClassLoader(_jc_env *env, _jc_object *clobj)
{
	return JCNI_java_lang_VMClass_getClassLoader(env, clobj);
}

