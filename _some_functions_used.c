#include "shell.h"

/**
 * _puts - To Print a string to the standard output stream
 * @_string: The string to print
 *
 * Return: Void
 */
void _puts(char *_string)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(_string);
	num_written = write(STDOUT_FILENO, _string, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
