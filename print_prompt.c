#include "shell.h"

/**
 * print_prompt - prints the prompt to stdio
 * @prompt: the prompt
 *
 * Return: 0
 */
int primt_prompt(char *prompt)
{
	if (isatty(0))
		_fputstr(1, prompt);
	return (0);
}
