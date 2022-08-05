#include "main.h"

/**
 * builtin - function to handle builtins
 * @argv: array of strings
 * @input: string from getline
 * Return: 1 if no matches
 */

int builtin(char *input, char **argv)
{
	if (_strcmp("exit", argv[0]) == 0)
	{
		free(input);
		exit(exit_code);
	}

	if (_strcmp("env", argv[0]) == 0)
	{
		_env();
		return (0);
	}

	return (1);
}
