/**
 * builtin - function to handle builtins
 * @argv: array of strings
 * Return: 1 if no matches
 */

int builtin(char **argv)
{
	if (_strcmp("exit", argv[0]) == 0)
	{
		free(argv)
		exit(0);
	}

	return (1);
}
