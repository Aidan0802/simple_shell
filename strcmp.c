#include "shell.h"

/**
 * _strcmp - compares to strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if strings are equal
 * greater than 0 if s1 compares greater s2
 * less than 0 if s1 compares s2
 */

int _strcmp(char *s1, char *s2)
{
	int i, match = 0;

	for (i = 0; match == 0; i++)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break;
		match = s1[i] - s2[i];
	}
	return (match);
}
