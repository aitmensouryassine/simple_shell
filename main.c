#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

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
	pid_t pid;

	line = malloc(sizeof(char) * size);
	if (!line)
		perror("Can't allocate memory");

	while (1)
	{
		printf("#cisfun ");

		if (getline(&line, &size, stdin) == -1)
			break;

		av[0] = strtok(line, "\n");

		pid = fork();
		if (pid == -1)
			perror("Error forking parent process");
		else if (pid == 0)
		{
			if(execve(av[0], av, NULL))
				perror(argv[0]);
		}
		else
			wait(NULL);
	}

	free(line);
	return (0);
}
