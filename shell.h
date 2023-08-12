#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

extern char **environ;

int _prompt(char **argv, char **buf);
int exec_cmd(char **argv, char *cmd);
char *get_path(char *cmd);
int exit_cmd(char *exit_val);

#endif
