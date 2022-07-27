#include "main.h"

/**
 * get_input - 
 */

char *get_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read = 0;

	read = getline(&input, &len, stdin);
	if (read == -1)
	{
		write(STDERR_FILENO, "\n", 1);
		return (NULL);
	}
	if (input[read - 1] == '\n')
		input[read - 1] = '\0';
	return (input);
}

/**
 * main - test of saving linked list item
 *
 * Return: 0 always
 */

int main(void)
{
	char *input = NULL;
	char **argv = NULL;

	while (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		input = get_input();
		argv = argarr(input);
		execve(argv[0], argv, NULL);
		free(argv);
	}
	return (0);
}
