
/*
 * @COPYRIGHT@
 *
 * $Id: prepare.c,v 1.3 2005/02/27 04:52:59 archiecobbs Exp $
 */

#include "libjc.h"

/*
 * Prepare a type.
 *
 * NOTE: This assumes the caller is handling synchronization issues.
 */
jint
_jc_prepare_type(_jc_env *env, _jc_type *type)
{
	jint status;

	/* Already prepared? */
	if (_JC_FLG_TEST(type, PREPARED)) {
		_JC_ASSERT(_JC_FLG_TEST(type, LOADED));
		_JC_ASSERT(_JC_FLG_TEST(type, VERIFIED));
		return JNI_OK;
	}

	/* Sanity check */
	_JC_ASSERT(!_JC_FLG_TEST(type, ARRAY));

	/* Verify type first */
	if (!_JC_FLG_TEST(type, VERIFIED)
	    && (status = _jc_verify_type(env, type)) != JNI_OK)
		return status;

	/* Nothing to do for us */

	/* Mark type as prepared */
	type->flags |= _JC_TYPE_PREPARED;

	/* Done */
	return JNI_OK;
}

