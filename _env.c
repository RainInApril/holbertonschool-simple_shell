#include "main.h"

/**
 *_env - prints out the environment
 *
 * Return: void
 */

void _env(void)
{
	int i = 0, env_len;

	while (environ[i] != NULL)
	{
		env_len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], env_len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
