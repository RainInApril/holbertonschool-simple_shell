#include "main.h"

char **argarr(char *str)
{
	list_t *head = NULL;
	char *token;
	char **argv;
	int listlen, i = 0;

	token = strtok(str, " ");
	add_node(&head, token);
	printf("token: %s\n", token);
        while (token != NULL)
	{
		token = strtok(NULL, " ");
		printf("token: %s\n", token);
		if (token != NULL)
			add_node_end(&head, token);
	}

	listlen = list_len(head);
	printf("list len:%d\n", listlen);
	argv = malloc(sizeof(char *) * listlen);

	while (i < listlen)
	{
		printf("head-str: %s\n", head->str);
		argv[i] = strdup(head->str);
		i++;
		head = head->next;
	}
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
	int i = 0;
	char **argv = NULL;

	while (1)
	{
		printf("$ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
			write(STDERR_FILENO, "Error\n", 7);
		argv = argarr(input);
		while (argv[i] != NULL)
		{
			printf("This is argv[%d]: %s\n", i, argv[i]);
			i++;
		}
	}

	return (0);
}
