#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _built_ins_setenv - To set the value of an environment variable
 * @args: Arguments the name and the value of the environment variable
 *
 * Return: Nothing
 */
int _built_ins_setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _built_ins_unsetenv - to unset an environment variable
 * @args: Arguments the name of the environment variable
 *
 * Return: Nothing
 */
int _built_ins_unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		_puterror("unsetenv");
	}
	return (0);
}
