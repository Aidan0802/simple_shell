#include "shell.h"

int handle_commands(char *commands, int cmd_count, char **copy)
{
	int exit_status = 0, i = 0, j;
	char *token = strtok(commands, ";"), *tok;
	char *argv[100], *cmds[100];

	while (token)
	{
	    argv[i++] = token;
	    token = strtok(NULL, ";");
	}
	argv[i++] = NULL;

	i = 0;
	while (argv[i])
	{
	    for (j = 0; j < 100; j++)
		    cmds[j] = NULL;
	    j = 0;

	    tok = strtok(&(*argv[i]), " \n");
	    cmds[j++] = tok;
	    if ((tok = strtok(NULL, " \n")))
		    while (tok)
		    {
			    cmds[j++] = tok;
			    tok = strtok(NULL, " \n");
		    }
	    if (cmds[0])
		    exit_status = exec_cmd(cmds, cmds[0], cmd_count, &(*copy));
	    i++;
	}

	return exit_status;
}
