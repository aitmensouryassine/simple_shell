#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * calculate_args - calculates number of args in command line
 * @line: the command
 * @del: the delimiter
 * Return: number of args
 */
int calculate_args(char *line, char *del)
{
	int count = 0;
	char *linecp, *chop;

	linecp = malloc(sizeof(char) * (_strlen(line) + 1));
	if (!linecp)
		return (0);
	_strcpy(linecp, line);

	chop = strtok(linecp, del);
	while (chop)
	{
		count++;
		chop = strtok(NULL, del);
	}
	free(linecp);

	return (count);
}

/**
 * create_av - creates av arguments for execve
 * @line: the command
 * Return: return the created av variable, or NULL on failure
 */
char **create_av(char *line)
{
	int i = 0, av_size;
	char *chop, del[] = " \t\n";
	char **av;

	/* calculate args count (av_size) */
	av_size = calculate_args(line, del);
	if (av_size == 0)
		return (NULL);

	/* allocate need memory for av */
	av = malloc(sizeof(*av) * (av_size + 1));
	if (!av)
		return (NULL);

	/* assign line to av */
	chop = strtok(line, del);
	while (chop)
	{
		write(STDOUT_FILENO, chop, _strlen(chop));
		/* copy chop into arg */
		av[i] = malloc(_strlen(chop) + 1);
		if (!av[i])
		{
			while (i--)
				free(av[i]);
			free(av);
			return (NULL);
		}
		_strcpy(av[i], chop);

		/* get next chop from line */
		chop = strtok(NULL, del);

		i++;
	}
	av[i] = NULL;

	return (av);
}
