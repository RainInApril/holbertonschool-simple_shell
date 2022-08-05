#include "main.h"

/**
 * builtin - function to handle builtins
 * @argv: array of strings
 * @input: string from getline
 * Return: 1 if no matches
 */

int builtin(char *input, char **argv, int *code)
{
	int exit_code = *code;

	if (_strcmp("exit", argv[0]) == 0)
	{
		free(code);
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
