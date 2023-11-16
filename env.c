#include "shell.h"

/**
 * print_environ - function to add env built in to print current environment
 * Return: void
 */
void print_environ(void)
{
	char **environ;
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		printf("%s\n", *env);
	}
}
