
/*
 * @COPYRIGHT@
 *
 * $Id: arch_structures.h,v 1.2 2004/12/14 03:03:25 archiecobbs Exp $
 */

#ifndef _ARCH_STRUCTURES_H_
#define _ARCH_STRUCTURES_H_

/************************************************************************
 *				Overview				*
 ************************************************************************/

/*

This purpose of this file is to define architecture-specific structures.
Here is a summary of structures that need to be defined by this file or
an included file:

Stack Frames
------------

This file must define a '_jc_stack_frame' type, an opaque type
representing a stack frame, with the following properties:

    - A stack frame is always associated with a function invocation,
      i.e., there is a calling function and a called function.
    - A stack frame is cabable of providing the return address in the
      calling function, i.e., the address of the next instruction to
      execute in the calling function after the called function returns.
    - A stack frame does not need to remain valid after the calling
      function returns.
    - Two stack frames can be compared for equality, where equality means
      they refer to the same caller -> callee invocation on the stack.
    - There must be an 'invalid' value not equal to any other value.
    - It is possible to get the 'current' stack frame.

*/

/************************************************************************
 *			Architecture-specific structures		*
 ************************************************************************/

#if defined(__i386__)
#include "i386/i386_structures.h"
#elif defined(__sparc__)
#include "sparc/sparc_structures.h"
#elif defined(__alpha__)
#include "alpha/alpha_structures.h"
#elif defined(__ia64__)
#include "ia64/ia64_structures.h"
#elif defined(__powerpc__)
#include "powerpc/powerpc_structures.h"
#else
#error "Unsupported architecture for architecture-specific structures"
#endif

#endif	/* _ARCH_STRUCTURES_H_ */

