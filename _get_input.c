#include "main.h"
#include <string.h>
#include <stdlib.h>
static char *last_input;
/**
 * _get_input - To read the input entered by the user.
 *
 * Return: A pointer to a buffer containing the user's input.
*/
char *_get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

	do {
		/* print shell prompt */
		prompt();

		/* get a line of input from user */
		nread = getline(&input, &input_size, stdin);

		/* check for EOF or error */
		if (nread == -1)
		{
			free(input);
			_puts("\n");
			return (NULL);
		}

		/* remove trailing newline character */
		input[nread - 1] = '\0';

		} while (input[0] == '\0' || isspace(input[0]));
		/* update last_input to point to the new input */
		last_input = input;
		return (input);
}

/**
 * _free_last_input - Frees the most recent input entered by the user.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. When the input string is no longer needed we should
 * call it.
 */
void _free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
