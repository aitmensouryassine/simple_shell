#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * tshell - runs when shell is called from terminal
 * @line: the command
 * @size: size of the command
 * @av: arguments to pass to execve
 * @argv: argument vector (passed to main)
 * @env: environment variable
 */
void tshell(char *line, size_t size, char **av, char **argv, char **env)
{
	char prompt[] = "$ ", notfound[] = ": No such file or directory\n";

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));

		if (getline(&line, &size, stdin) == -1)
			break;

		if (_strcmp(line, ENTER) == 0)
			continue;

		if (_strcmp(line, EXIT) == 0)
		{
			free(line);
			exit(0);
		}

		av = create_av(line);

		if (check_cmd(av) == 1)
		{
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, notfound, _strlen(notfound));
			continue;
		}

		_execve(av[0], av, env, argv[0]);
	}
}
