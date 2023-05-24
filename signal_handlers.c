#include "main.h"
#include <signal.h>
#include <unistd.h>

/**
 * sigHandler - signals handler
 * @sig: signal number
 */
void sigHandler(int sig)
{
	char prompt[] = "\n$ ";

	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
}
