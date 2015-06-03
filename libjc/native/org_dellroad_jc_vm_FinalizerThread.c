
/*
 * @COPYRIGHT@
 *
 * $Id: org_dellroad_jc_vm_FinalizerThread.c,v 1.3 2005/05/15 21:41:01 archiecobbs Exp $
 */

#include "libjc.h"
#include "org_dellroad_jc_vm_FinalizerThread.h"

/*
 * static native void finalizeObjects()
 */
void _JC_JCNI_ATTR
JCNI_org_dellroad_jc_vm_FinalizerThread_finalizeObjects(_jc_env *env)
{
	if (_jc_gc_finalize(env) != JNI_OK)
		_jc_throw_exception(env);
}

