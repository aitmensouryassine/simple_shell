#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _built_ins_setenv - To set the value of an environment variable
 * @argmts: Arguments the name and the value of the environment variable
 *
 * Return: Nothing
 */
int _built_ins_setenv(char **argmts)
{
	char *_name, *value;

	if (argmts[1] == NULL || argmts[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	_name = argmts[1];
	value = argmts[2];

	if (setenv(_name, value, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _built_ins_unsetenv - to unset an environment variable
 * @argmts: Arguments the name of the environment variable
 *
 * Return: Nothing
 */
int _built_ins_unsetenv(char **argmts)
{
	char *_name;

	if (argmts[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	_name = argmts[1];

	if (unsetenv(_name) != 0)
	{
		_puterror("unsetenv");
	}
	return (0);
}
