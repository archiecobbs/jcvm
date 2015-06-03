
/*
 * @COPYRIGHT@
 *
 * $Id: main.c,v 1.2 2005/01/13 04:44:59 archiecobbs Exp $
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "jc_invoke.h"

int
main(int ac, char **av)
{
	int status = 0;

	/* Invoke the JC VM */
	switch (_jc_invoke(ac, (const char **)av, 1, vfprintf)) {
	case _JC_RETURN_NORMAL:
		break;
	case _JC_RETURN_ERROR:
	case _JC_RETURN_EXCEPTION:
		status = 1;
		break;
	}

	/* Done */
	return status;
}

