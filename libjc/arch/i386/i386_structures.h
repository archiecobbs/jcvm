
/*
 * @COPYRIGHT@
 *
 * $Id: i386_structures.h,v 1.1.1.1 2004/02/20 05:15:49 archiecobbs Exp $
 */

#ifndef _ARCH_I386_STRUCTURES_H_
#define _ARCH_I386_STRUCTURES_H_

/*
 * i386 stack frame:
 *
 *	| ...         |
 *	+-------------+
 *	| param2      |
 *	+-------------+
 *	| param1      |
 *	+-------------+
 *	| param0      |
 *	+-------------+
 *	| return addr |
 *	+-------------+
 *	| saved %epb  |    <== %ebp
 *	+-------------+
 *	| locals...   |
 *
 * So all we need is a pointer to the saved %epb register.
 */

typedef _jc_word	*_jc_stack_frame;	/* pointer to saved %epb */

#endif	/* _ARCH_I386_STRUCTURES_H_ */

