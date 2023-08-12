#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int _prompt(char **, char **);
int exec_cmd(char **, char *);
char *get_path(char *cmd);

#endif
