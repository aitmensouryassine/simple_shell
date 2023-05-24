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
	char **av;
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
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		_execve(av[0], av, env, argv[0]);
	}

	free(line);
	return (0);
}
