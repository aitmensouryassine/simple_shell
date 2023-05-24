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

	line = malloc(sizeof(char) * size);
	if (!line)
	{
		perror("Can't allocate memory");
		return (1);
	}

	signal(SIGINT, sigHandler);
	signal(SIGTSTP, SIG_IGN);

	if (!isatty(STDIN_FILENO))
	{
		pshell(line, size, av, argv, env);
		free(line);
		return (0);
	}

	tshell(line, size, av, argv, env);

	free(line);
	return (0);
}
