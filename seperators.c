#include "shell.h"

int handle_commands(char **commands, int cmd_count)
{
    int exit_status = 0;
    char *token = strtok(*commands, ";");
    char *cmd_token = strtok(token, " \n");
    char *argv[100];
    int argc;

    while (token) 
    {
		argc = 0;
		cmd_token = strtok(token, " \n");
		while (cmd_token != NULL)
		{
			argv[argc++] = cmd_token;
			cmd_token = strtok(NULL, " \n");
		}
		argv[argc] = NULL;
		
		exit_status = exec_cmd(argv, argv[0], cmd_count, &(*commands));
		
		token = strtok(NULL, ";");
    }

    return exit_status;
}
