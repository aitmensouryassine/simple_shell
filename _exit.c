#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * myexit - exit
 * @st: exit status
 * @name: shell
 * @av: command
 */
void myexit(char *st, char *name, char **av)
{
	int status = 0;
	char errmsg[50] = "Illegal number: ";

	if (!st)
		status = 0;
	else if (st[0] == '0')
		status = 0;
	else
	{
		if (_atoi(st) == 0)
		{
			_strcat(errmsg, st);
			_strcat(errmsg, "\n");
			_perror(errmsg, name, av);
			status = 0;
		}
		else
		{
			status = atoi(st);
		}
	}
	exit(status);
}
