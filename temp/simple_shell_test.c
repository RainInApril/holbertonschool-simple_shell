#include "main.h"

char **argarr(char *str)
{
	list_t *head = NULL;
	char *token;
	char **argv;
	int listlen, i = 0;

	token = strtok(str, " ");
	add_node(&head, token);
	 while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
			add_node_end(&head, token);
	}

	listlen = list_len(head);
    	argv = malloc(sizeof(char *) * listlen);

	while (i < listlen)
	{
		argv[i] = strdup(head->str);
		i++;
		head = head->next;
	}
	argv[i] = NULL;
	free_list(head);
	return (argv);
}

/**
 *main - test of saving linked list item
 *
 * Return: 0 always
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read = 0;
	char **argv = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		read = getline(&input, &len, stdin);
		if (read == -1)
			write(STDERR_FILENO, "Error\n", 7);
		argv = argarr(input);
		execve(argv[0], argv, NULL);
		free(argv);
	}
	return (0);
}
