#include "shell.h"

/**
 * _getline - Gets entire line input
 *
 * @lineptr: The address that input should be stored
 * @n: The size that must be allocated
 * @stream: The input string
 * Return: Amount of characters, othewise -1 (Error).
 */

int _getline(char **lineptr, size_t *n, FILE *stream)
{
	int count = 0;
	char c;

	*lineptr = malloc(sizeof(char) * (*n));
	if (!(*lineptr))
	{
		free(*lineptr);
		return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (c == -1)
		{
			free(*lineptr);
			return (-1);
		}
		(*lineptr)[count] = c;
		count++;
		if (c == '\n')
			break;

	}
	if (count == 0)
	{
		free(*lineptr);
		return (-1);
	}
	(*lineptr)[count] = '\0';
	return (count);
}
