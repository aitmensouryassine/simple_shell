#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _built_in_cd - To change the current working directory
 * @args: Represents an array of arguments
 */
void _built_in_cd(char **args)
{
	char *direc = args[1];
	int ret;

	/* If there are no arguments, change to HOME directory */
	if (direc == NULL)
	{
		direc = _getenv("HOME");
		if (direc == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(direc);
	if (ret == -1)
	{
		perror("cd");
	}
}
