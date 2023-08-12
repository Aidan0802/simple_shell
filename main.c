#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *av[100], *buf = NULL, *cmd = NULL;
	int run = 1, val, res;

	while (run)
	{
		val = _prompt(av, &buf);
		if (val == 2)
			break;
		else if (val == 1)
		{
			free(buf);
			continue;
		}
		cmd = av[0];

		res = exec_cmd(av, cmd);
		if (res == 2)
			break;
		free(buf);
	}
	free(buf);
	return (0);
}
