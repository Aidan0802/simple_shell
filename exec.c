#include "shell.h"
#include <ctype.h>

/**
 * exec_cmd - Executes commands
 * @cmd: Command to be executed
 * @cmd_count: Amount of commands.
 * @argv: Argument vector address
 * @buf: Address of buffer
 * Return: -1 (Success), -3 (Failed), -2 (Exit)
 * exit_stat if provided.
 */

int exec_cmd(char **argv, char *cmd, int cmd_count, char **buf)
{
	pid_t id;
	char *exe_cmd, **envi = environ, newString[100];
	int status;

	if (_strcmp(cmd, "exit") == 0)
		exit_cmd(argv[1], &(*buf));

	if (_strcmp(cmd, "env") == 0)
	{
		while (*envi)
		{
			printf("%s\n", *envi);
			envi++;
			return (0);
		}
	}
	exe_cmd = get_path(cmd, newString);
	if (exe_cmd == NULL)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_count, argv[0]);
		return (127);
	}

	id = fork();
	if (id == 0)
	{
		status = execve(exe_cmd, argv, NULL);
		exit(1);
	}
	else
	{
		waitpid(id, &status, 0);
		/*if (access(argv[1], F_OK) != 0)
			exit_cmd("2", &(*buf));*/
		/*if (access(cmd, 0) != 0)
			free(exe_cmd);*/
		return (0);
	}
}

/**
 * exit_cmd - Exits shell.
 * @exit_val: Exit value.
 * @buf: Address to buffer
 * Return: Exit status.
 */

int exit_cmd(char *exit_val, char **buf)
{
	int exit_stat;

	if (exit_val != NULL)
	{
		if (!isdigit(*exit_val))
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", exit_val);
			free(*buf);
			exit(2);
		}

		exit_stat = atoi(exit_val);
		if (exit_stat < 0)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", exit_val);
			free(*buf);
			exit(2);
		}
		free(*buf);
		exit(exit_stat);
	}
	else
	{
		free(*buf);
		exit(0);
	}
}
