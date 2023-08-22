#include "shell.h"

/**
 * _strdup - returns pointer to newly allocated space
 * in memory
 *
 * @str: string
 *
 * Return: returns NULL if string is NULL
 * returns a pointer to duplicated string if succesful
 * returns NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	int i, len = 0;
	char *buffer = NULL;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		len++;

	buffer = malloc(len + 1);
	if (buffer == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		buffer[i] = str[i];

	return (buffer);
}

