#include "shell.h"

/**
 * _setenv - set/unset envronment variables
 * @argv: argument address
 * Return: 0 (found), -1 (not found)
 */

int _setenv(char **argv)
{
	if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] == NULL || argv[2] == NULL)
		{
			dprintf(STDERR_FILENO, "Usage: setenv VARIABLE VALUE.\n");
			return (0);
		}
		else if (setenv(argv[1], argv[2], 1) == 0)
			return (0);
		dprintf(STDERR_FILENO, "Could not set environment of variable.\n");
		return (0);
	}
	if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] == NULL)
		{
			dprintf(STDERR_FILENO, "Usage: setenv VARIABLE.\n");
			return (0);
		}
		else if (unsetenv(argv[1]) == 0)
			return (0);
		dprintf(STDERR_FILENO, "Could not unset environment of variable.\n");
		return (0);
	}
	return (-1);
}
