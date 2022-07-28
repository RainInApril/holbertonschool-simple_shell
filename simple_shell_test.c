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
 *
 * Return: 0 always
 */

int main(int ac,__attribute__ ((unused)) char *argv[], char **env)
{
	char *input = NULL;
	char **args = NULL;
	pid_t child_id;
	int status, i;

	while (ac)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		input = get_input();
		if (input == NULL)
			exit(0);

		args = argarr(input);

		child_id =  fork();
		if (child_id == -1)
			exit(1);

		if (child_id == 0)
		{
			if (execve(args[0], args, env) == -1)
				exit (1);
		}
		else
		{
			wait(&status);
			i = 0;
			while (args[i] != NULL)
			{
				free(args[i]);
				i++;
			}
			free(args);
		}
	}
	return (0);
}
