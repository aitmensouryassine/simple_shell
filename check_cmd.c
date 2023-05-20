#include "main.h"
#include <limits.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

/**
 * check_cmd - check if command exist, and return full path if it does
 * @av: contains pathname, and argv (args of execve)
 * Return: 0 on success, 1 on failure (cmd doesn't exist)
 */
int check_cmd(char **av)
{
	char PATH_TMP[PATH_MAX], cmd_path[PATH_MAX];
	char *chop;
	struct stat st;

	if (stat(av[0], &st) == 0)
		return (0);

	_strcpy(PATH_TMP, _getenv("PATH"));
	chop = strtok(PATH_TMP, ":");
	while (chop)
	{
		_strcpy(cmd_path, chop);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, av[0]);

		if (stat(cmd_path, &st) == 0)
		{
			av[0] = realloc(av[0], sizeof(cmd_path));
			_strcpy(av[0], cmd_path);
			return (0);
		}

		chop = strtok(NULL, ":");
	}

	return (1);
}
