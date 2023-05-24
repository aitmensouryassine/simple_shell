#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * main - Simple shell in c
 * @argc: argument count
 * @argv: argument vector
 * @env: the environment variable
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *line;
	size_t size = 1;
	char **av = NULL;
	char prompt[] = "$ ";

	line = malloc(sizeof(char) * size);
	if (!line)
	{
		perror("Can't allocate memory");
		return (1);
	}

	signal(SIGINT, sigHandler);
	signal(SIGTSTP, SIG_IGN);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		fflush(stdout);

		if (getline(&line, &size, stdin) == -1)
			break;

		if (_strcmp(line, ENTER) == 0)
			continue;

		av = create_av(line);
		if (!av)
			continue;

		if (_strcmp(av[0], EXIT) == 0)
		{
			free(line);
			myexit(av[1], argv[0], av);
		}

		if (check_cmd(av) == 1)
		{
			_perror("not found\n", argv[0], av);
			continue;
		}

		_execve(av[0], av, env, argv[0]);
	}

	free(line);
	return (0);
}
