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
