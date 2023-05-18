#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Simple shell in c
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line;
	size_t size = 1;
	char *av[] = {NULL, NULL};

	line = malloc(sizeof(char) * size);
	if (!line)
		perror("Can't allocate memory");

	while (1)
	{
		printf("#cisfun ");

		if (getline(&line, &size, stdin) == -1)
			break;

		av[0] = strtok(line, "\n");

		_execve(av[0], av, NULL, argv[0]);
	}

	free(line);
	return (0);
}
