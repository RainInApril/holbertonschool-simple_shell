#include "main.h"

int exit_code = 0;

/**
 * get_input - grabs the input from the user.
 *
 * Return: returns pointer to string
 */

char *get_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		free(input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}
	if (input[read - 1] == '\n')
		input[read - 1] = '\0';
	return (input);
}

/**
 * main - test of saving linked list item
 * @ac: count of args passed through
 * @argv: args passed through
 * @env: environment variables passed through
 * Return: 0 always
 */

int main(int ac, char *argv[], char **env)
{
	char *input = NULL;
	char *args[64];
	char *name = argv[0];
	int i = 0;

	signal(SIGINT, ctrlc);
	while (ac)
	{
		i++;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		input = get_input();

		if (input == NULL)
			exit(0);

		if (argarr(args, input) == 0)
		{
			if (check_args(input, args, name, env, i) == -1)
				exit(0);
		}
		free(input);
	}
	return (0);
}
