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

int _prompt(char **argv, char **buf, char **copy);
int exec_cmd(char **argv, char *cmd, int, char **);
char *get_path(char *cmd, char *);
int exit_cmd(char *exit_val, char **buf);
int _getline(char **lineptr, size_t *n, FILE *stream);
int _chdir(char **av, int);
char *_strtok(char *str, const char *delim);
int _setenv(char **argv);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _putchar(int c);

/**
 * struct als - Alias struct
 * @name: Alias name
 * @value: Alias value
 */

typedef struct als
{
	char *name;
	char *value;
} Alias;

Alias *find_alias(const char *name);
void display_aliases(void);
void add_or_mod(const char *name, const char *value);
void _alias(char **argv);
void cleanup_aliases(void);
char *alias_check(char *);
int handle_commands(char *, int, char **);

extern Alias aliases[100];
extern size_t alias_count;

#endif
