#include "shell.h"

/**
 * exec_cmd - Executes commands
 * @cmd: Command to be executed
 * @argv: Argument vector address
 * Return: 0 (Success), 1 (Failed), 2 (Exit);
 */

int exec_cmd(char **argv, char *cmd)
{
	pid_t id;
	char *exe_cmd;

	if (strcmp(cmd, "exit") == 0)
		return (2);

	exe_cmd = get_path(cmd);
	if (exe_cmd == NULL)
	{
		perror("./shell");
		return (1);
	}

	id = fork();
	if (id == 0)
	{
		execve(exe_cmd, argv, NULL);
		exit(1);
	}
	else
	{
		waitpid(id, NULL, 0);
		if (access(cmd, 0) != 0)
			free(exe_cmd);
		return (0);
	}
}
