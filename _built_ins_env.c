#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _builts_ins_env - To print all the environment variables.
 *
 * Return: Void.
 */
int _builts_ins_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	return (0);
}
