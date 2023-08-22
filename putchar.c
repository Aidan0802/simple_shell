#include "shell.h"

/**
 * _putchar - Print character
 * @c: Input
 * Return: Character value.
 */

int _putchar(int c)
{
	return (write(1, &c, 1));
}
