#include "shell.h"

int handle_commands(char *commands, int cmd_count)
{
    int exit_status = 0;
    char *token = strtok(commands, ";");
    char *trimmed_token;
    char **argv;
    int argc = 0;
    char *cmd_token;

    while (token != NULL) {
        trimmed_token = token;

        while (*trimmed_token == ' ' || *trimmed_token == '\t')
            trimmed_token++;

        if (*trimmed_token != '\0')
	{
            argv = malloc(100 * sizeof(char *));
            cmd_token = strtok(trimmed_token, " \n");

            while (cmd_token != NULL)
	    {
                *argv[argc++] = *cmd_token;
                cmd_token = strtok(NULL, " \n");
            }
            argv[argc] = NULL;

            exit_status = exec_cmd(argv, argv[0], cmd_count, &commands);

            free(argv);
        }

        token = strtok(NULL, ";");
    }

    return exit_status;
}
