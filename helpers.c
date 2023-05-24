#include <unistd.h>

void pnum(int n);

/**
 * _strlen - returns the length of a string
 * @str: the string
 * Return: the length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * _strcpy - copy the source string to the destination string
 * @dest: destination string
 * @src: source string
 */
void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * _strcat - copy the source string to the destination string
 * @dest: destination string
 * @src: source string
 */
void _strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int src_len = _strlen(src);
	int i = 0;

	while (i < src_len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}

/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if s1 and s2 are equal, negative/positif if s1 is less/greater
 * then s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int s1_len = _strlen(s1);
	int s2_len = _strlen(s2);
	int cmp = 0;
	int i = 0;

	while ((i < s1_len || i < s2_len) && cmp == 0)
	{
		cmp = s1[i] - s2[i];
		i++;
	}

	return (cmp);
}

/**
 * _strncmp - compares first @n bytes of two strings
 * @s1: the first string
 * @s2: the second string
 * @n: first n bytes to compare
 * Return: 0 if s1 and s2 are equal, negative/positif if s1 is less/greater
 * then s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int cmp = 0;
	size_t i = 0;

	while (i < n && (s1[i] || s2[i]))
	{
		cmp = s1[i] - s2[i];
		if (cmp != 0)
			return (cmp);

		i++;
	}

	return (cmp);
}

/**
 * cmd_not_found - prints cmd not found
 * @name: name of the program
 * @av: the command
 */
void _perror(char *message, char *name, char **av)
{
	static int call = 1;
	char sep[] = ":", sp[] = " ";

	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, sep, 1);
	write(STDOUT_FILENO, sp, 1);
	pnum(call);
	write(STDOUT_FILENO, sep, 1);
	write(STDOUT_FILENO, sp, 1);
	write(STDOUT_FILENO, av[0], _strlen(av[0]));
	write(STDOUT_FILENO, sep, 1);
	write(STDOUT_FILENO, sp, 1);
	write(STDOUT_FILENO, message, _strlen(message));

	call = call + 1;
}

/**
 * pnum - prints a number
 * @n: the number to print
*/
void pnum(int n)
{
	char minus[] = "-";
	unsigned int x;
	char num;

	if (n < 0)
	{
		x = -n;
		write(STDOUT_FILENO, minus, 1);
	} else
	{
		x = n;
	}

	if (x / 10)
	{
		pnum(x / 10);
	}
	num = (x % 10) + '0';

	write(STDOUT_FILENO, &num, 1);
}

