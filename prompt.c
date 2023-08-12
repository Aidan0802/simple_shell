#include "shell.h"

/**
 * _prompt - prompts user for input
 *
 * @av: Argument address
 * @buf: input buf
 * Return: 0 (Success), 1 (Failed) 2 (Exit)
 */

int _prompt(char **av, char **buf)
{
	int i = 0, end;
	size_t max = 100;
	char *tok;

	*buf = NULL;

	if (isatty(STDIN_FILENO))
		printf("# ");

	end = getline(&(*buf), &max, stdin);
	if (end == -1)
	{
		if (*buf[0] == '\0')
		{
			putchar('\n');
			return (2);
		}
		else
			return (2);

	}

	if (*buf[0] == '\n')
		return (1);

	tok = strtok(*buf, " \n");

	while (tok)
	{
		av[i++] = tok;
		tok = strtok(NULL, " \n");
	}
	av[i] = NULL;

	return (0);
}
