#include "main.h"

/**
 * argarr - initialises an array of pointers
 * @str: string to be broken into pointers
 * Return: char **
 */

int argarr(char **args, char *str)
{
        int i = 0;
	char *token;

	token = strtok(str, " \t\n\r");

	if (token == NULL)
	{
		return (1);
	}

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n\r");
		i++;
	}

	args[i] = NULL;

	return (0);
}
