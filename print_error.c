#include "main.h"

/**
 * print_error - prints an error message when command is not found
 * @argv: the command
 * Return: void
 */

void print_error(char *argv)
{
	write(STDOUT_FILENO, argv, _strlen(argv));
	write(STDOUT_FILENO, "command: not found\n", 19);
}
