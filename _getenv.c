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
	char *nametmp;
	int i = 0, len = 0;

	(void)len;

	nametmp = malloc(sizeof(char) * (_strlen(name) + 2));
	if (!nametmp)
		return (NULL);

	_strcpy(nametmp, name);
	_strcat(nametmp, "=");
	len = _strlen(nametmp);

	while (env[i])
	{
		if (_strncmp(nametmp, env[i], len) == 0)
		{
			free(nametmp);
			return (&env[i][len]);
		}

		i++;
	}
	return (NULL);
}
