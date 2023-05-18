#include <stdlib.h>
#include <string.h>

/**
 * create-av - creates av arguments for execve
 * @line: the command
 * Return: return the created av variable, or NULL on failure
 */
char **create_av(char *line)
{
	int size = 0;
	char *chop;
	char **tmp, **av;

	av = malloc(sizeof(*av) * (size + 1));
	if (!av)
		return (NULL);

	chop = strtok(line, " \n");
	while (chop)
	{
		/* copy chop into arg */
		av[size] = malloc(strlen(chop) + 1);
		strcpy(av[size], chop);

		/* get next chop from line */
		chop = strtok(NULL, " \n");

		/* increment size of av */
		size++;
		/* allocate memory */
		tmp = realloc(av, sizeof(*av) * (size + 1));
		if (!tmp)
		{
			while (size--)
				free(av[size]);
			free(av);
			return (NULL);
		}
		av = tmp;
	}
	av[size] = NULL;

	return (av);
}
