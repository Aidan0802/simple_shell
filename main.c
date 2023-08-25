#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: 0 (Success), error (ERRNO)
 */

int main(void)
{
	char *av[100], *buf = NULL, *cmd = NULL;
	int run = 1, res = 0, val = 0, _cd = 0, set = 0, cmd_count = 0;

	while (run)
	{
		val = _prompt(av, &buf);
		cmd_count++;
		if (val == 2)
			break;
		else if (val == 1)
		{
			free(buf);
			continue;
		}
		if (_strcmp(av[0], "alias") == 0)
		{
			_alias(av), free(buf);
			continue;
		}
		set = _setenv(av);
		if (set == 0)
		{
			free(buf);
			continue;
		}
		_cd = _chdir(av, cmd_count);
		if (_cd == 0)
		{
			free(buf);
			continue;
		}
		cmd = av[0];
		res = exec_cmd(av, cmd, cmd_count, &buf);
		free(buf);
	}
	free(buf);
	return (res);
}
