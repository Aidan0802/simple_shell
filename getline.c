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
	size_t count = 0;
	static size_t buf_pos, buf_size;
	char buf[BUF_SIZE];

	if (buf_pos >= buf_size)
	{
		buf_size = read(fileno(stream), buf, BUF_SIZE);
		buf_pos = 0;
	}
	if (buf_size == 0)
		return (-1);

	*lineptr = malloc(sizeof(char) * (buf_size + 1));
	if (!(*lineptr))
	{
		free(*lineptr);
		return (-1);
	}

	while (buf_pos < buf_size)
	{
		if (count >= (*n - 1) || ((*lineptr)[count] == '\n'))
			break;
		(*lineptr)[count] = buf[buf_pos++];
		count++;
	}
	(*lineptr)[count] = '\0';
	return (count);
}
