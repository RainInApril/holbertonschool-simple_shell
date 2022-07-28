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
/* if the command line starts by / or . Then consider as executable */
	if (cmdToExecute[0] == '/' || cmdToExecute[0] == '.')
	{
		cmdToExecute = argv[0];
	}
/* if the first argument of the command line is empty then consider as error */
	if (argv[0] == NULL)
	{
		perror("Error : no argument");
	}
/* if there is no standard function to call then consider as an error' */
	if (cmdToExecute == NULL)
	{
		free(cmdToExecute);
		perror("Error : execve");
		return (0);
	}
/* otherwise, main case, execute the function called by the first argument in the command line */
	else
		execve(cmdToExecute, argv, NULL);

	return (1);
}
