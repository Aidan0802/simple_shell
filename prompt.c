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
	process_alias_input(*copy);
	remove_comments(*copy);
	if (*copy[0] == '\0')
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
void process_alias_input(char *input)
{
	if (strncmp(input, "alias", 5) == 0)
	{
		char *copy = strdup(input);
		char *tok = _strtok(copy, " \n");
		
		if (tok)
		{
			tok = _strtok(NULL, " \n");
			while (tok)
			{
				_alias(tok);
				tok = _strtok(NULL, " \n");
			}
		}else
			_alias(tok);

		free(copy);
		input[0] = '\0';
	}
}
