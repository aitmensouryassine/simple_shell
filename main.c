#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Simple shell in c
 * Return: Always 0
 */
int main(void)
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
		printf("%s\n", av[0]);
	}

	free(line);
	return (0);
}
