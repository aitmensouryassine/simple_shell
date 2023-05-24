#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * _check_char - To check if a character matchs any other character
 * @s: the character to check
 * @_string: string of delimiters
 * Return: Returns 0 on success and -1 on failure
 */
unsigned int _check_char(char s, const char *_string)
{
		unsigned int i;

		for (i = 0; _string[i] != '\0'; i++)
		{
			if (s == _string[i])
				return (1);
		}
		return (0);
}

/**
 * _strtok - To extract tokens of a string
 * @_string: A string
 * @delim: delimiter
 * Return: Returns a pointer to the next token or NULL
 */
char *_strtok(char *_string, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

		if (_string != NULL)
		{
			new_token = _string;
			tokens = new_token;
		}
		if (tokens == NULL)
			return (NULL);
		for (i = 0; tokens[i] != '\0'; i++)
		{
			if (_check_char(tokens[i], delim) == 0)
				break;
		}
		if (new_token[i] == '\0' || new_token[i] == '#')
		{
			new_token = NULL;
			return (NULL);
		}
		tokens = new_token + i;
		new_token = tokens;
		for (i = 0; new_token[i] != '\0'; i++)
		{
			if (_check_char(new_token[i], delim) == 1)
				break;
		}
		if (new_token[i] == '\0')
			new_token = NULL;
		else
		{
			new_token[i] = '\0';
			new_token = new_token + i + 1;
			if (*new_token == '\0')
				new_token = NULL;
		}
		return (tokens);
}
