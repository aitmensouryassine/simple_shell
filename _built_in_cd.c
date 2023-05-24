#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _built_in_cd - To change the current working directory
 * @argmts: Represents an array of arguments
 */
void _built_in_cd(char **argmts)
{
	char *direc = argmts[1];
	int retn;

	/* If there are no arguments, it will change to HOME directory */
	if (direc == NULL)
	{
		direc = _getenv("HOME");
		if (direc == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	retn = chdir(direc);
	if (retn == -1)
	{
		perror("cd");
	}
}
