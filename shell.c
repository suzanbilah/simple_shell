#include "shell.h"

/**
 * execute_com - implementing the prompt
 * @com: it holds the name of the executable
 * @back: to determine whether command should be executed in the background
 *
 * Return: void
 */
void execute_com(char *com, int back)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(com, com, (char *)NULL) == -1)
		{
			perror("Command failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!background)
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Error from child process");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status) && WEITSTATUS(status) != 0)
			{
				fprintf(stderr, "Exit status\n");
			}
		}
	}
}

/**
 * main - entry point
 *
 * Return: 0 always
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	int back = 0;

	while (1)
	{
		printf("$v");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("error reading input");
				exit(EXIT_FAILURE);
			}
		}
		input[strcspn(input, "\n")] = '\0';
		if (strlen(input) == 0)
			continue;

		if (strcmp(input, "exit") == 0)
			exit(EXIT_SUCCESS);

		execute_com(input, back);
	}

	return (0);
}
