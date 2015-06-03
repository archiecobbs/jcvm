
/*
 * @COPYRIGHT@
 *
 * $Id: java_io_VMObjectStreamClass.c,v 1.5 2005/11/09 18:14:22 archiecobbs Exp $
 */

#include "libjc.h"
#include "java_io_VMObjectStreamClass.h"

/*
 * static final native boolean hasClassInitializer(Class)
 */
jboolean _JC_JCNI_ATTR
JCNI_java_io_VMObjectStreamClass_hasClassInitializer(_jc_env *env,
	_jc_object *class)
{
	_jc_jvm *const vm = env->vm;
	_jc_type *type;

	/* Check for null and get type */
	if (class == NULL) {
		_jc_post_exception(env, _JC_NullPointerException);
		_jc_throw_exception(env);
	}
	type = *_JC_VMFIELD(vm, class, Class, vmdata, _jc_type *);

	/* Look for class initializer */
	return _jc_get_declared_method(env, type, "<clinit>",
	    "()V", _JC_ACC_STATIC, _JC_ACC_STATIC) != NULL;
}

