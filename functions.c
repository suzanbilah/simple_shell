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

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(tokens[0], token) == -1)
		{
			perror("Command failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!back)
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Command returned non-zero\n");
			}
		}
	}
}

/**
 *
