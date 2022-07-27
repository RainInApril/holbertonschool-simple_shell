#include "main.h"

/**
 * main - prints each directory in the PATH var
 *
 *Return: 0 always
 */

int main(void)
{
	char *path = _getenv("PATH");
	char *token;

	token = strtok(path, "=");
	token = strtok(NULL, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	return (0);
}
