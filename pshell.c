#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * pshell - runs when stdin is from pipe
 * @line: the command
 * @size: size of the command
 * @av: arguments to pass to execve
 * @argv: argument vector (passed to main)
 * @env: environment variable
 */
void pshell(char *line, size_t size, char **av, char **argv, char **env)
{
	int status;

	while (getline(&line, &size, stdin) != -1)
	{
		if (_strcmp(line, ENTER) == 0)
			continue;

		av = create_av(line);
		if (!av)
			continue;

		if (_strcmp(av[0], EXIT) == 0)
		{
			free(line);
			__exit(av[1]);
		}

		if (check_cmd(av) == 1)
		{
			_perror("not found\n", argv[0], av);
			continue;
		}

		_execve(av[0], av, env, argv[0]);
	}
}
