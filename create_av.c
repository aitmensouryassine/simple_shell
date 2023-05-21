#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_av - creates av arguments for execve
 * @line: the command
 * Return: return the created av variable, or NULL on failure
 */
char **create_av(char *line)
{
	int i = 0, av_size = 0;
	char *chop, *linecp, del[] = " \n";
	char **av;

	/* calculate args count (av_size) */
	linecp = malloc(sizeof(char) * (_strlen(line) + 1));
	if (!linecp)
		return (NULL);
	_strcpy(linecp, line);

	chop = strtok(linecp, del);
	while (chop)
	{
		av_size++;
		chop = strtok(NULL, del);
	}
	free(linecp);

	/* allocate need memory for av */
	av = malloc(sizeof(*av) * (av_size + 1));
	if(!av)
		return (NULL);

	/* assign line to av */
	chop = strtok(line, del);
	while (chop)
	{
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
		chop = strtok(NULL, " \n");

		i++;
	}
	av[i] = NULL;

	return (av);
}
