#include "main.h"

/**
 * get_input - grabs the input from the user.
 *
 * Return: returns pointer to string
 */

char *get_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read = 0;

	read = getline(&input, &len, stdin);
	if (read == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
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
		if (execve(argv[0], argv, NULL) == -1)
			exit (1);
		free(argv);
	}
	return (0);
}
