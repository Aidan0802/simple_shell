#include "shell.h"

/**
 * _chdir - Changes directory
 * @av: Address of argumetns
 * @cmd_count: Command count
 * Return: 1 (not dir) 0 (Success);
 */

int _chdir(char **av, int cmd_count)
{

static char prev[BUF_SIZE];
char temp[BUF_SIZE], *path = getenv("OLDPWD");
char *home = getenv("HOME");
int val;

_strcpy(temp, prev);
if (_strcmp(av[0], "cd") == 0)
{
	if (av[1] == NULL)
	{
		getcwd(prev, BUF_SIZE);
		if (!home)
			return (0);
		chdir(home);
		return (0);
	}
	if (_strcmp(av[1], "-") == 0)
	{
		getcwd(prev, BUF_SIZE);
		if (strcmp(path, "\0") == 0)
		{
			printf("%s\n", prev);
			return (0);
		}
		printf("%s\n", temp);
		chdir(temp);
		return (0);
	}
	else
	{
		getcwd(prev, BUF_SIZE);
		val = chdir(av[1]);
		if (val == -1)
		{
			fprintf(stderr, 
			"./hsh: %d: cd: can't cd to %s\n", cmd_count, av[1]);
			return (0);
		}
		return (0);
	}
}

return (1);
}
