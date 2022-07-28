#include "main.h"

/**
 * find_command - finds the command sent through
 * @argv: an array of pointers to string
 *Return: 0 on success
 */

int find_command(char **argv)
{
	int access_check;
	path_t *head = NULL;
	char* path;

	if (*argv[0] == '/')
	{
		access_check = access(argv[0], F_OK | X_OK);
		if (access_check == -1)
		{
			perror("Can not access location");
		}
	}


	return (0);

}

