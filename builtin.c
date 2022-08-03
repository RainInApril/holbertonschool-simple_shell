#include "main.h"

/**
 * _isalpha - checks to see if char is letter
 * @c: char being check
 * Return: 0 on true, 1 other wise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/**
 * _atoi - returns an int from a string
 * @s: the string being searched
 * Return: converted int of string passed through
 */

int _atoi(char *s)
{
	int numcount = 0, i = 0, j, multiplier = 1, negative = 1;
	int number = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			numcount++;
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				break;
		}
		i++;
	}
	while (numcount > 1)
	{
		multiplier = multiplier * 10;
		numcount--;
	}
	for (j = 0; j <= i; j++)
	{
		if (s[j] == '-')
			negative = negative * -1;
		else if (s[j] >= '0' && s[j] <= '9')
		{
			number = number + (s[j] - 48) * multiplier * negative;
			multiplier = multiplier / 10;
		}
	}

	return (number);
}

/**
 * builtin - function to handle builtins
 * @argv: array of strings
 * @input: string from getline
 * Return: 1 if no matches
 */

int builtin(char *input, char **argv)
{
	int i, flag = 0, code;

	if (_strcmp("exit", argv[0]) == 0)
	{
		i = 0;
		while (argv[1][i])
		{
			if (_isalpha(argv[1][i]) == 1)
				flag = 1;
			i++;
		}
		if (flag == 0)
		{
			code = _atoi(argv[1]);
			free(input);
			exit(code);
		}
		free(input);
		exit(errno);
	}

	if (_strcmp("env", argv[0]) == 0)
	{
		_env();
		return (0);
	}

	return (1);
}
