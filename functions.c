#include "shell.h"

/**
 * execute_com - function to execute command
 * @com: the command to be executed
 * @back:m the background
 *
 * Return: nothing
 */
void execute_com(char **com, int back)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(com[0], com) == -1)
		{
			perror("Command failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!back)
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Command returned non-zero\n");
			}
		}
	}
}

/**
 * token_input - function to tokenize the command
 * @input: the input
 * @token: the token
 * Return: token count
 */
int token_input(char *input, char **token)
{
	int token_count = 0;
	char *token_start = input;
	char *token_end = input;
	size_t token_length;

	while (*token_end != '\0')
	{
		while (*token_start == ' ' || *token_start == '\t')
		{
			++token_start;
		}
		token_end = token_start;
		while (*token_end != '\0' && *token_end
				!= ' ' && *token_end != '\t')
		{
			++token_end;
		}
		token_length = token_end - token_start;
		if (token_start != token_end)
		{
			token[token_count] = (char *)malloc(token_length + 1);
			strncpy(token[token_count], token_start, token_length);
			token[token_count][token_length] = '\0';
			++token_count;
		}
		token_start = token_end + 1;
	}
	token[token_count] = NULL;
	return (token_count);
}

/**
 * background_check - to check if the command runs in background
 * @token: the token
 * @token_count: the number of token
 * Return: background
 */
int background_check(char **token, int *token_count)
{
	int background;

	if (*token_count > 0 && strcmp(token[*token_count - 1], "&") == 0)
	{
		background = 1;
		free(token[--(*token_count)]);
	}
	return (background);
}

/**
 * free_token - funtion to free memory
 * @token: memory to be freed
 * Return: void
 */
void free_token(char **token)
{
	int i = 0;

	if (token == NULL)
		return;
	while (token[i] != NULL)
	{
		free(token[i]);
		i++;
	}
	free(token);
}

/**
 * handle_builtin - function to add builtin arguements
 * @token: the commands
 * Return: 1 if ture else 0
 */
int handle_builtin(char **token)
{
	int exit_status = EXIT_SUCCESS;

	if (strcmp(token[0], "exit") == 0)
	{
		if (token[1] != NULL)
		{
			exit_status = atoi(token[1]);
		}
		exit(exit_status);
		return (1);
	}
	else if (strcmp(token[0], "env") == 0)
	{
		print_environ();
		return (1);
	}
	return (0);
}
