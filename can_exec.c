#include "main.h"

/**
 * can_exec - function that  checks if a command is executable
 * @argv: list of arguments
 * Return: 1
 */

int can_exec(char **argv)
{
/* define *cmdToExecute as the first arguments passed in the command line */
	char *cmdToExecute = argv[0];

/* if the first argument of the command line is empty then consider as error */
	if (argv[0] == NULL)
	{
		perror("Error : no argument");
	}
/* if the command line starts by / or . Then consider as executable */
	if (cmdToExecute[0] == '/' || cmdToExecute[0] == '.')
	{
		if (access(cmdToExecute,F_OK | X_OK) == 1)
		{
			free(cmdToExecute);
			return (1);
		}
	}
	free(cmdToExecute);
	return (0);
}
