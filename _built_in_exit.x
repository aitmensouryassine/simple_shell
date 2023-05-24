#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _built_in_exit - To exit the shell.
 * @args: The arguments.
 *
 * Return: It returns nothing.
 */
void _built_in_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();
	exit(status);
}
