#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv - set/unset envronment variables
 * @argv: argument address
 * Return: 0 upon success or -1 upon failure
 */

int _setenv(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		dprint(stderr, "could not find environment variable.\n");
	return (-1);

}

if (strcmp(argv[0], "setenv") == 0)
{ 
	if (setenv(av,val,1) == 0)
	{
		return (0);
	}
	else
	{
		dprintf(fileno(stderr), "modify environment of variable.\n");
		return (-1);
	}
}


