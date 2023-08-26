#include "shell.h"

/**
 * _prompt - prompts user for input
 *
 * @av: Argument address
 * @buf: input buf
 * Return: 0 (Success), 1 (Failed) 2 (Exit)
 */

int _prompt(char **av, char **buf, char **copy)
{
	int i = 0, end = 0;
	size_t max = 100;
	char *tok;

	*buf = NULL;
	if (isatty(STDIN_FILENO))
	{
		_putchar('#'), _putchar(' ');
		fflush(stdout);
	}
	end = getline(&(*buf), &max, stdin);
	if (end == -1)
	{
		return (2);
	}
	if (*buf[0] == '\n')
		return (1);
	*copy = strdup(*buf);
	remove_comments(*copy);
	if (*copy[0] == '\0' )
	{
		free(*copy);
		*copy = NULL;
		return (1);
	}
	tok = strtok(*copy, " \n");
	while (tok)
	{
		av[i++] = tok;
		tok = strtok(NULL, " \n");
	}
	if (i == 0)
		return (1);
	av[i] = NULL;
	process_alias_input(av);
	if (av[0] == NULL )
	{
		free(*copy);
		return (1);
	}
	return (0);
}
/**
 * remove_comments - Removes anything after #
 * @str: Input String
 * Return: void
 */

void remove_comments(char *str)
{
	char *commentPos = strstr(str, " #");
	
	if (str[0] == '#')
	{
		str[0] = '\0';
		return;
	}

	if (commentPos != NULL)
	{
		*commentPos = '\0';
	}
}
void process_alias_input(char **input)
{
	if (strcmp(input[0], "alias") == 0)
	{
		if (input[1])
		{
			int i = 1;

			while (input[i])
			{
				_alias(input[i]);
				i++;
			}
		}else
			_alias(input[0]);
		input[0] = NULL;
		return;
	}
}
