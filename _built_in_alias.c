#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _built_in_alias - To add a node to a linked list
 * @first: The first node
 * @key: The key to add in node
 * @value:The value that will be added with the key
 *
 * Return: Return 0 on success and -1 on failure
 */

int _built_in_alias(alias **first, char *key, char *value)
{
	alias *node, *_first;

	if (!first)
		return (-1);

	node = _malloc(sizeof(alias));
	node->key = _strdup(key);
	node->value = _strdup(value);
	node->next = NULL;
	if (!*first)
	{
		*first = node;
		return (0);
	}
	_first = *first;
	while (_first->next)
	{
		if (!_strcmp(_first->key, key))
		{
			free(_first->value);
			_first->value = _strdup(value);
			_free_alias(node);
			return (0);
		}
		_first = _first->next;

	}
	_first->next = node;
	return (0);
}

/**
 * _print_content_alias - To print the contents of a linked list
 * @first: first node
 * Return: Return 0 on success and -1 on failure
 */

int _print_content_alias(alias *first)
{
	if (!first)
		return (-1);

	while (first)
	{


		_write(-1, NULL, 0);
		_write(1, first->key, _strlen(first->key));
		_write(1, "='", 2);
		_write(1, first->value, _strlen(first->value));
		_write(1, "'\n", 2);
		_write(1, NULL, 0);

		first = first->next;
	}
	return (0);
}
/**
 * _print_contents_node_alias - Prints contents of a node whose key is key
 * @first: first node
 * @key: the key of the node to be printed
 *
 * Return: Returns 0 on success and -1 on failure
 */
int _print_contents_node_alias(alias *first, char *key)
{
	char *messg, *sm;

	if (!first)
	{
		errno = -5;
		messg = _malloc(_strlen("not found ") + _strlen(key) + 4);
		_strcpy(messg, "not found ");
		sm = _malloc(_strlen("alias: ") + _strlen(key) + 4);
		_strcpy(sm, "alias: "), _strcat(sm, key);
		print_error(sm, NULL, messg);
		free(messg), free(sm);
		return (-1);
	}

	while (first)
	{
		if (!_strcmp(first->value, key))
		{
			_write(-1, NULL, 0);
			_write(1, first->key, _strlen(first->key));
			_write(1, "='", 2);
			_write(1, first->value, _strlen(first->value));
			_write(1, "'\n", 2);
			_write(1, NULL, 0);
			return (0);
		}
		first = first->next;
	}
	errno = -3;
	messg = _malloc(_strlen("not found ") + _strlen(key) + 4);
	_strcpy(messg, "not found ");
	sm = _malloc(_strlen("alias: ") + _strlen(key) + 4);
	_strcpy(sm, "alias: "), _strcat(sm, key);
	print_error(sm, NULL, messg);
	free(messg), free(sm);
	return (-1);
}

/**
 * _handle_flags_alias - To handle flags for aliases
 * @argmt: arguments
 * @aliasfirst: first node
 *
 * Return: Returns 0 on success and -1 on failure
 */

int _handle_flags_alias(char **argmt, alias **aliasfirst)
{
	int argmtc = _arlen(argmt);
	int i = 0;
	char **tmp = NULL;

	if (argmtc == 0)
		return (-1);

	if (argmtc == 1)
		_print_content_alias(*aliasfirst);

	if (argmtc > 1)
	{
		i += 1;
		while (argmt[i])
		{
			parse_args(argmt[i], "=", &tmp, 0);
			if (_arlen(tmp) > 1)
				_built_in_alias(aliasfirst, tmp[0], tmp[1]);
			else
				_print_contents_node_alias(*aliasfirst, tmp[0]);
			free_pp(tmp);
			i++;
		}
	}
	return (0);
}

/**
 * _free_alias - To free alias linked list
 * @first: first node
 * Return: Returns 0 on success and -1 on failure
 */

int _free_alias(alias *first)
{
	alias *tmp;

	while (first)
	{
		tmp = first->next;
		free(first->key);
		free(first->value);
		free(first);
		first = tmp;
	}
	return (0);
}
