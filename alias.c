#include "shell.h"

/**
 * _alias - Set/modify/remove aliases
 * @argv: Argument vector
 * Return: void
 */


void _alias(char *av)
{
	char *tok[2];

	printf("%s\n", av);
	tok[0] = strtok(av, "=");
	tok[1] = strtok(NULL, "\0");

	if (av == NULL)
	{
		display_aliases();
	}
	else if (tok[0] && tok[1] == NULL)
	{
		Alias *alias = find_alias(tok[0]);

		if (alias)
			printf("%s='%s'\n", alias->name, alias->value);
		else
			fprintf(stderr, "Alias not found: %s\n", tok[0]);
	} else if (tok[0] && av[1])
		add_or_mod(tok[0], tok[1]);
}

/**
 * display_aliases - Displays all
 * Return: void
 */

void display_aliases(void)
{
	size_t i;

	for (i = 0; i < alias_count; i++)
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
}
/**
 * add_or_mod - Add or modify aliases
 * @name: Name of alias
 * @value: Value of alias
 * Return: void
 */

void add_or_mod(const char *name, const char *value)
{
	Alias *alias = find_alias(name);

	if (alias)
	{
		free(alias->value);
		alias->value = strdup(value);
	}
	else
	{
		if (alias_count < 100)
		{
			aliases[alias_count].name = strdup(name);
			aliases[alias_count].value = strdup(value);
			alias_count++;
		}
		else
		    fprintf(stderr, "Alias limit reached.\n");
	}
}

/**
 * find_alias - search for alias
 * @name: Name of alias
 * Return: Name (Success), NULL (not found)
 */

Alias *find_alias(const char *name)
{
	size_t i;

	for (i = 0; i < alias_count; i++)
		if (strcmp(aliases[i].name, name) == 0)
			return (&aliases[i]);
	return (NULL);
}
