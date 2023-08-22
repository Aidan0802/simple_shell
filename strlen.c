#include "shell.h"

/**
 * _strlen - calculates the string length
 *
 * @s: string that should be counted
 *
 * Return: returns the length of the string
 */

int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i]; i++)
	{
		count++;
	}
	return (count);

}
