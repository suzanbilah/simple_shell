#include "shell.h"

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
		printf("$ ");
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
		
		if (input[strlen(input) -1] == '&')
		{
			back = 1;
			input[strlen(input) - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
			exit(EXIT_SUCCESS);

		execute_com(input, back);
	}

	return (0);
}
