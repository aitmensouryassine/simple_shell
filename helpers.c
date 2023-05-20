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
