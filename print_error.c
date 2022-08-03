#include "main.h"

/**
 * print_error - prints an error message when command is not found
 *
 * @argv: the command
 * @name: name of program
 * @i: count of times a command has been entered
 * Return: void
 */

void print_error(char *argv, char *name, int i);
{
	int name_len, arg_len;
	char count[3];

	name_lem = _strlen(name);
	arg_len = _strlen(argv);
	if (i < 10)
	{
		count[0] = i + '0';
		count[2] = '\0';
	}
	else
	{
		count[0] = i / 10;
		count[1] = i % 10;
		count[2] = '\0';
	}

	write(STDERR_FILENO, name, name_len);
	write(STDERR_FILENO, ": ", 2);
	if (count < 10)
		write(STDERR_FILENO, count, 1);
	else
		write(STDERR_FILENO, count, 2);

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv, arg_len);
	write(STDERR_FILENO, ": not found", 13);
}
