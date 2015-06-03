
/*
 * @COPYRIGHT@
 *
 * $Id: verify.c,v 1.3 2005/02/27 04:52:59 archiecobbs Exp $
 */

#include "libjc.h"

/*
 * Verify a type.
 *
 * We don't verify yet. But note: this could be implemented in Java.
 *
 * NOTE: This assumes the caller is handling synchronization issues.
 */
jint
_jc_verify_type(_jc_env *env, _jc_type *type)
{
	/* Already verified? */
	if (_JC_FLG_TEST(type, VERIFIED)) {
		_JC_ASSERT(_JC_FLG_TEST(type, LOADED));
		return JNI_OK;
	}

	/* Sanity check */
	_JC_ASSERT(!_JC_FLG_TEST(type, ARRAY));

	/* XXX verify class here */

	/* Mark type as verified */
	type->flags |= _JC_TYPE_VERIFIED;

	/* Done */
	return JNI_OK;
}

