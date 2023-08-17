#include "shell.h"

/**
 * _strtok - Creates string tokens
 * @str: String to be tokenized
 * @delim: Delimiter
 * Return: Tokeninzed string
 */

char *_strtok(char *str, const char *delim)
{
	static char *next;
	int i, pos = 0;

	if (str)
		next = str;

	if (*next == '\0')
		return (NULL);

	while (*next)
	{
		for (i = 0; delim[i]; i++)
		{
			if (delim[i] == *next)
			{
				*next = '\0';
				next++;
				return (next - (pos + 1));
			}
		}
		pos++, next++;
	}
	return (next - pos);
}
