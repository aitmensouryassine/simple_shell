#include <stdio.h>
#include <stdlib.h>

/**
 * main - Simple shell in c
 * Return: Always 0
 */
int main(void)
{
	char *line;
	size_t size = 1;

	line = malloc(sizeof(char) * size);

	printf("#cisfun ");
	getline(&line, &size, stdin);
	printf("%s\n", line);

	free(line);
	return (0);
}
