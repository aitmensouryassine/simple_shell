#include "main.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>

/**
 * _getenv - get an environment variable value
 * @name: The name of the variable
 * Return: return a pointer to the value of the env variable
 */
char *_getenv(const char *name)
{
	char **env = environ;
	char tmp[PATH_MAX];
	int i = 0;

	while (env[i])
	{
		_strcpy(tmp, env[i]);
		if (_strcmp(strtok(tmp, "="), name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
