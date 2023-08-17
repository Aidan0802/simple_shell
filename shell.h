#ifndef SHELL_H
#define SHELL_H

#define BUF_SIZE 1024

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
int _getline(char **lineptr, size_t *n, FILE *stream);
int _chdir(char **av);
char *_strtok(char *str, const char *delim);

#endif
