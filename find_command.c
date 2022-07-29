#include "main.h"

path_t *create_path_list(path_t *head)
{
	char *path = _getenv("PATH");
	char *token = ()
	path_t *node;

	save_path(&head, token);
	while (token != NULL)
	{
		token = strtok(NULL, ":");
		if (token != NULL)
			save_path_end(&head, token);
	}
	free(path);
	return (node);
}

/**
 * find_command - finds the command sent through
 * @argv: an array of pointers to string
 *Return: 0 on success
 */

int find_command(char **argv, char **env)
{
	int access_check;
	path_t *node, *head = NULL;
	char *command = NULL;

	create_path_list(head);

	node = head;
	while (node != NULL)
	{
		_strcat(command, node->str);
		_strcat(command, argv[0]);
		/* check command is in PATH */

		node = node->next
	}

	return (0);

}
