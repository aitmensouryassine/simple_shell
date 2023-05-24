#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _get_line - Allows to read the input from the standard input.
 *
 * Return: It returns the string entered by the user.
*/
void *_get_line(void)
{
	static char buff[BUFF_SIZE];
	static int buf_position, buf_size;
	char *input_str = NULL;
	char current_char;
	int input_length = 0;

	while (1)
	{
		if (buf_position >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buff, BUFF_SIZE);
			buf_position = 0;
			if (buf_size == 0)
				return (input_str);
				else if (buf_size < 0)
				{
					perror("read");
					return (NULL);
				}
		}

		current_char = buff[buf_position];

		buf_position++;
		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_length + 1);
			input_str[input_length] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_length + 1);
			input_str[input_length] = current_char;
			input_length++;
		}
	}
}
