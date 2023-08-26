#include "shell.h"

/**
 * _prompt - prompts user for input
 *
 * @av: Argument address
 * @buf: input buf
 * Return: 0 (Success), 1 (Failed) 2 (Exit)
 */

int _prompt(char **av, char **buf, char **copy, int status)
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
	handle_variables(copy, status);
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


void replace_variable(char **str, const char *var, const char *replacement)
{
    char *pos = strstr(*str, var);
        size_t var_len = strlen(var);
        size_t rep_len = strlen(replacement);
        size_t tail_len = strlen(pos + var_len);
    while (pos)
    {
        memmove(pos + rep_len, pos + var_len, tail_len + 1);
        memcpy(pos, replacement, rep_len);
        pos = strstr(pos + rep_len, var);
    }
}

void handle_variables(char **str, int exit_status)
{
    char pid_str[16];
    char exit_status_str[16]; 
  
    if (strstr(*str, "$?")) {
        sprintf(exit_status_str, "%d", exit_status);
        replace_variable(str, "$?", exit_status_str);
    }
 
    if (strstr(*str, "$$")) {
        pid_t pid = getpid();
        sprintf(pid_str, "%d", pid);
        replace_variable(str, "$$", pid_str);
    }
}
