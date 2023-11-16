#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 always
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	int background = background_check(token, &token_count);
	int token_count = token_input(input, token);
	char *token[MAX_TOKENS];

	while (1)
	{
		display_prompt();
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error reading input");
				exit(EXIT_FAILURE);
			}
		}
		input[strcspn(input, "\n")] = '\0';
		if (token_count == 0)
			continue;
		if (handle_builtin(token) == 1)
		{
			free_token(token);
			continue;
		}
		execute_com(com, back);
		free_token(token);
	}
	return (0);
}
