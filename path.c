#include "shell.h"

/**
 * get_path - Searches for the command.
 * @cmd: Command.
 * Return: Path of command.
 */

char *get_path(char *cmd)
{
	char *pathEnv = getenv("PATH");
	char *p_cpy = _strdup(pathEnv), *s_path;
	char *path = strtok(p_cpy, ":\n");
	int size;

	if (!path)
		return (NULL);

	while (path)
	{
		if (access(cmd, 0) == 0)
		{
			free(p_cpy);
			return (cmd);
		}

		size = _strlen(path) + _strlen(cmd);
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
