#include "shell.h"

/**
 * get_path - Searches for the command.
 * @cmd: Command.
 * Return: Path of command.
 */

char *get_path(char *cmd, char *newString)
{
	char *pathEnv = getenv("PATH");
	char *p_cpy = strdup(pathEnv), *s_path;
	char *path = strtok(p_cpy, ":\n");/* *alias_;*/
	int size;

	if (!path)
		return (NULL);

	/*alias_ = alias_check(cmd);
	if (alias_)
	{
		newString[0] = '/';
		strcpy(newString + 1, alias_);
		cmd = newString;
	}*/
	newString = NULL;
	if (newString != NULL)
		cmd = newString;

	if (access(cmd, 0) == 0)
	{
		free(p_cpy);
		return (cmd);
	}

	while (path)
	{

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


char *alias_check(char *cmd)
{
	size_t i;

	for (i = 0; i < alias_count; i++)
		if (strcmp(aliases[i].name, cmd) == 0)
		{
			if (access(&aliases->value[i], F_OK) == 0)
				return (&aliases->value[i]);
			else
			{
				return (&aliases->value[i]);
			}
		}
	return (NULL);
}
