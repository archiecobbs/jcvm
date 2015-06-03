
/*
 * @COPYRIGHT@
 *
 * $Id: jni_machdep.h,v 1.1.1.1 2004/02/20 05:15:11 archiecobbs Exp $
 */

#ifndef _JNI_MACHDEP_H_
#define _JNI_MACHDEP_H_

/*
 * Goal: define JNI C typedefs for Java primitive types.
 */

#if (defined (__ia64__) || defined (__alpha__) || defined (__i386__) || defined(__sparc__))

typedef	unsigned char	jboolean;
typedef	signed char	jbyte;
typedef	unsigned short	jchar;
typedef	signed short	jshort;
typedef	signed int	jint;
typedef	long long	jlong;
typedef float		jfloat;
typedef double		jdouble;

#else
#error "Unsupported architecture"
#endif

#endif	/* _JNI_MACHDEP_H_ */
