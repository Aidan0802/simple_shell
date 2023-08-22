#include "shell.h"

/**
 * _strcpy - copies a string
 *
 * @dest: destination to be copied to
 * @src: the source to copy
 *
 * Return: the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] >= '\0'; i++)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break;
	}
	return (dest);

}
