#include "main.h"

/**
 * __exit - exit
 * @st: exit status
 */
void __exit(char *st)
{
	int status;

	if (!st)
		status = 0;
	else
		status = atoi(st);
        }

	exit(status);
}
