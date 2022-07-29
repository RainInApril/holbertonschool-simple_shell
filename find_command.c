#include "main.h"

path_t *create_path_list(path_t *head)
{
	char *path = _getenv("PATH");
	char *token;
	path_t *node;

	token = strtok(path, "=");
	token = strtok(NULL, ":");
	save_path(&head, token);
	while (token != NULL)
	{
		token = strtok(NULL, ":");
		if (token != NULL)
			save_path_end(&head, token);
	}
	free(token);
	free(path);
	return (node);
}

/**
 * find_command - finds the command sent through
 * @argv: an array of pointers to string
 *Return: 0 on success
 */

char *find_command(char *argv)
{
	path_t *node, *head = NULL;
	char *command;
	int comannd_len, path_len;

	create_path_list(head);
	if (head == NULL)
		return (NULL);

	command_len = _strlen(argv);
	node = head;
	while (node != NULL)
	{
		path_len = _strlen(node->str);
		command = malloc(sizeof(char) * (command_len + path_len) + 2);
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
	free(command);
	free_path_list(head);
	return (argv);
}

int check_args(char **argv,char **env)
{
	char *path = NULL;

	printf("argv[0]: %s\n", argv[0]);

	if (argv[0] == '/' || argv[0] == '.')
	{
		if (can_exec(argv[0]) == -1)
		{
			perror("Can not locate");
			return (-1);
		}
	}
	else
	{
		path = find_command(argv[0]);
		if (path == NULL)
			return (-1);
		else if (path == argv[0])
		{
			free(path);
			if (can_exec(argv[0]) == -1)
			{
				perror("Cant locate");
				return (-1);
			}
		}
		else {
			argv[0] = path;
		}
	}
	printf("argv: %s", argv);
	/* fork_exec(argv, env); */
	return (0);
}
