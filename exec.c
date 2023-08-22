#include "shell.h"

/**
 * exec_cmd - Executes commands
 * @cmd: Command to be executed
 * @argv: Argument vector address
 * Return: -1 (Success), -3 (Failed), -2 (Exit)
 * exit_stat if provided.
 */

int exec_cmd(char **argv, char *cmd, int cmd_count)
{
	pid_t id;
	char *exe_cmd, **envi = environ;

	if (strcmp(cmd, "exit") == 0)
		return (exit_cmd(argv[1]));

	exe_cmd = get_path(cmd);
	if (exe_cmd == NULL)
	{
		fprintf(stderr, "./shell: %d: %s: Not found\n", cmd_count, argv[0]);
		exit(127);
	}
	if (strcmp(cmd, "env") == 0)
		while (*envi)
		{
			printf("%s\n", *envi);
			envi++;
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
		return (-1);
	}
}

/**
 * exit_cmd - Exits shell.
 * @exit_val: Exit value.
 * Return: Exit status.
 */

int exit_cmd(char *exit_val)
{
	int exit_stat;

	if (exit_val)
	{
		exit_stat = atoi(exit_val);
		return (exit_stat);
	}
	else
		return (-2);
}
