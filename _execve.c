#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _execve - execute program with a child process
 * @cmd: command name
 * @args: command args
 * @env: environemnt variable
 * @name: program name
 */
void _execve(char *cmd, char **args, char **env, char *name)
{
	pid_t pid = fork();
	int i = 0;

	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(cmd, args, env))
		{
			perror(name);
			exit(1);
		}
	}
	else
	{
		wait(NULL);

		/* free args */
		while (args[i])
			free(args[i++]);
		free(args);
	}
}
