#include "shell.h"
#include <stdio.h>
/**
 * _setenv - set/unset envronment variables
 * @argv: argument address
 * Return: 0 upon success or -1 upon failure
 */

int _setenv(char **, argv)
{
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


