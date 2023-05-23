#include <stdio.h>
#include <signal.h>

/**
 * sigHandler - signals handler
 * @sig: signal number
 */
void sigHandler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n$ ");
		fflush(stdout);
	}
}
