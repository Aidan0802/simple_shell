#include "shell.h"

/**
 * get_path - Searches for the command.
 * @cmd: Command.
 * Return: Path of command.
 */

char *get_path(char *cmd)
{
	const char *pathEnv = getenv("PATH");
	char *p_cpy = strdup(pathEnv), *s_path;
	char *path = strtok(p_cpy, ":\n");
	int size;

	while (path)
	{
		if (access(cmd, 0) == 0)
		{
			free(p_cpy);
			return (cmd);
		}

		size = strlen(path) + strlen(cmd);
		s_path = malloc(sizeof(char) * size + 2);
		sprintf(s_path, "%s/%s", path, cmd);
		if (access(s_path, 0) == 0)
		{
			free(p_cpy);
			return (s_path);
		}
		free(s_path);
		path = strtok(NULL, ":\n");
	}
	free(p_cpy);
	return (NULL);
}
