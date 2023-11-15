#include "shell.h"

/**
 * change_dir - a function that changes a current working directory
 * to a new directory
 * @directory: The current directory
 */
void change_dir(char *directory)
{
	char *new_directory;

	if (directory == NULL || strcmp(directory, "~") == 0)
	{
		new_directory = getenv("HOME");
	}
	else if (strcmp(directory, "-") == 0)
	{
		new_directory = getenv("OLDPWD");
	}
	else
	{
		new_directory =  directory;
	}

	if (chdir(new_directory) == -1)
	{
		perror("Error changing directory");
	}
	else
	{
		char cwd[MAX_INPUT_SIZE];

		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			set_environ_var("PWD", cwd);
		}
		else
		{
			perrpr("Error updating PWD");
		}
	}
}
