#include "shell.h"
/**
 * read_input - helper function to read input
 * @input: the input
 * Return:void
 */
void read_input(char *input)
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
}

/**
 * allocate_copy_tokens -function to allocate memory and copy tokens
 * @token: the token
 * @token_count:the number of token
 * Return: com
 */
char **allocate_copy_tokens(char **token, int token_count)
{
	char **com = malloc((token_count + 1) * sizeof(char *));
	int i;

	if (com == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < token_count; i++)
	{
		com[i] = strdup(token[i]);
		if (com[i] == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}
	}
	com[token_count] = NULL;

return (com);
}

/**
 * process_input - combines tokenization,handling builtin commands
 * @input: the input
 * @token: the token
 * @com: the command to be executrd
 * @token_count: number of tokens
 * @back: the background
 * Return: nothing
 */
void process_input(char *input, char **token,
		char ***com, int *token_count, int *back)
{
	*token_count = token_input(input, token);

	if (*token_count == 0)
	{
		return;
	}
	if (handle_builtin(token) == 1)
	{
		free_token(token);
		return;
	}

	*back = background_check(token, token_count);
	*com = allocate_copy_tokens(token, *token_count);
}

/**
 * main - entry point
 *
 * Return: 0 always
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *token[MAX_TOKENS];
	int token_count;
	char **com = NULL;
	int back;

	while (1)
	{
		read_input(input);

		process_input(input, token, &com, &token_count, &back);

		execute_com(com, back);

		free_token(com);
		free_token(token);
	}

	return (0);
}
