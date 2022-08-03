#include "main.h"

/**
 * create_path_list - creates a linked list of the PATH contained in
 * the environ
 * @head: Pointer to the started of the list
 * Return: pointer to pointer to start of list
 */

path_t **create_path_list(path_t **head)
{
	char *path = _getenv("PATH");
	char *token;

	path = _strdup(path);
	token = strtok(path, "=");
	token = strtok(NULL, ":");

	while (token != NULL)
	{
		save_path(head, token);
		token = strtok(NULL, ":");
	}
	free(token);
	free(path);
	return (head);
}

/**
 * find_command - finds the command sent through
 * @argv: an array of pointers to string
 *Return: 0 on success
 */

char *find_command(char *argv)
{
	path_t *node, *head = NULL;
	char *command = NULL;
	int command_len, path_len;

	create_path_list(&head);
	command_len = _strlen(argv);
	node = head;
	while (node != NULL)
	{
		path_len = _strlen(node->str);
		command = malloc(sizeof(char) * (command_len + path_len + 2));
		_strcpy(command, node->str);
		_strcat(command, "/");
		_strcat(command, argv);


		if (can_exec(command) == 0)
		{
			free_path_list(head);
			return (command);
		}
		free(command);
		node = node->next;
	}

	free_path_list(head);
	return (argv);
}

/**
 * check_args - function that takes the input from the user, check the arg is a
 * an executable or builds a path to executable
 * @input: input from getline
 * @argv: tokens from input
 * @name: argv[0] from initalisation of program
 * @env: environmental variables
 * @i: count of commands sent through
 * Return: 0 on sucess
 */

int check_args(char *input, char **argv, char *name, char **env, int i)
{
	char *path = NULL;

	if (builtin(input, argv) == 0)
		return (0);
	if (*argv[0] == '/' || *argv[0] == '.')
	{
		if (can_exec(argv[0]) == -1)
		{
			print_error(argv[0], name, i);
			free(input);
			return (0);
		}
	}
	else
	{
		path = find_command(argv[0]);
		if (path == NULL)
		{
			print_error(argv[0], name, i);
			return (0);
		}
		else if (path == argv[0])
		{
			if (access(argv[0], F_OK | X_OK) != 0)
			{
				print_error(argv[0], name, i);
				free(input);
				exit(127);
			}
		}
		else
			argv[0] = path;
	}
	fork_exec(argv, env);
	if (argv[0] == path)
		free(argv[0]);
	return (0);
}
