#include "main.h"

/**
 * can_exec - function that  checks if a command is executable
 * @argv: list of arguments
 * Return: 0 on success, -1 otherwise
 */

int can_exec(char *argv)
{

/* if the first argument of the command line is empty then consider as error */
	if (argv == NULL)
	{
		perror("Error : no argument");
		return (-1)
	}
/* if the command line starts by / or . Then consider as executable */
	if (access(argv,F_OK | X_OK) == 1)
	{
		return (0);
	}
	return (-1);
}
