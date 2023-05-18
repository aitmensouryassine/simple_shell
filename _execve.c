#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

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

	if (pid == -1)
		perror("Error forking parent process");
	else if (pid == 0)
	{
		if (execve(cmd, args, env))
			perror(name);
	}
	else
	{
		wait(NULL);
	}
}
