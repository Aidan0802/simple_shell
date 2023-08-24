#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *av[100], *buf = NULL, *cmd = NULL;
	int run = 1, val, res = 0, _cd, set, cmd_count = 0;

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
