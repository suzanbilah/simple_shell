#include "shell.h"

/**
 * print_environ - function to add env built in to print current environment
 * Return: void
 */
void print_environ(void)
{
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		printf("%s\n", *env);
	}
}

/**
 * set_environ_var - function to set environment to sentenv
 * @variable: the variable
 * @value: the value to be assigned to the variable
 * Return: void
 */
void set_environ_var(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) == -1)
	{
		perror("Error setting environment variable");
	}
}

/**
 * unset_environ_var - function to unset environment to sentenv
 * @variable: the variable
 * Return: void
 */
void unset_environ_var(const char *variable)
{
	if (unsetenv(variable) == -1)
	{
		perror("Error unsetting environment variable");
	}
}
