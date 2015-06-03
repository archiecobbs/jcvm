
/*
 * @COPYRIGHT@
 *
 * $Id: os_functions.c,v 1.1.1.1 2004/02/20 05:15:42 archiecobbs Exp $
 */

#include "libjc.h"

/*

This file contains O/S dependent (but architecture independent) functions.
The following functions must be defined here:

    int
    _jc_num_cpus(_jc_env *env)

	This function should return the number of CPU's. It is used
	to implement the Runtime.availableProcessors() method.

 */

/************************************************************************
 *				FreeBSD					*
 ************************************************************************/

#if defined(__FreeBSD__)

#include <sys/sysctl.h>

int
_jc_num_cpus(_jc_env *env)
{
	static const char *const node = "hw.ncpu";
	_jc_jvm *const vm = env->vm;
	int num;

        if (sysctlbyname(node, NULL, 0, &num, sizeof(num)) == -1) {
		_jc_eprintf(vm, "sysctl(%s): %s", node, strerror(errno));
		return 1;
	}
	return num;
}

/************************************************************************
 *				Linux					*
 ************************************************************************/

#elif defined(__linux__)

int
_jc_num_cpus(_jc_env *env)
{
	_jc_jvm *const vm = env->vm;
        static const char *const file = "/proc/cpuinfo";
	char buf[64];
	size_t len;
	FILE *fp;
	int num;
	int ch;

        if ((fp = fopen("/proc/cpuinfo", "r")) == NULL) {
		_jc_eprintf(vm, "%s: %s", file, strerror(errno));
		return 1;
	}
	for (num = 0; fgets(buf, sizeof(buf), fp) != NULL; ) {
		len = strlen(buf);
		if (len > 0 && buf[len - 1] != '\n')
			while ((ch = getc(fp)) != '\n' && ch != EOF);
		if (strncmp(buf, "processor", 9) == 0)
			num++;
	}
	fclose(fp);
	return num;
}

/************************************************************************
 *				Others					*
 ************************************************************************/

#else
#error "Unsupported operating system"
#endif

