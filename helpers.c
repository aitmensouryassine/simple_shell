/**
 * _strlen - returns the length of a string
 * @str: the string
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
 * _strcpy - copy the source string to the destination string
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
