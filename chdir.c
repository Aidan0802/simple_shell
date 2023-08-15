#include "shell.h"

/**
 * _chdir - Changes directory
 * @av : Address of argumetns
 * Return: 1 (not dir) 0 (Success);
 */

int _chdir(char **av)
{

	static char prev[BUF_SIZE];
	static char temp[BUF_SIZE];
	char *home;
	int val;

	getcwd(prev, BUF_SIZE);
	if (strcmp(av[0], "cd") == 0)
	{
		if (av[1] == NULL)
		{
			home = getenv("HOME");
			chdir(home);
			return (0);
		}
		if (strcmp(av[1], "-") == 0)
		{
			strcpy(temp, prev);
			chdir(temp);
			return (0);
		}
		else
		{
			val = chdir(av[1]);
			if (val == -1)
				perror("chdir");
			return (0);
		}
	}

	return (1);
}
