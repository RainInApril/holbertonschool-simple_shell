#include "main.h"

/**
 * _getenv - get environment variable
 * @name: name of var
 * Return: pointer to variabe
 */

char *_getenv(const char *name)
{
	int i, j, match;
	char *curr_env = NULL;

	i = 0;
	while (environ[i] != NULL)
	{
		match = 0;
		j = 0;
		curr_env = environ[i];
		while (curr_env[j] != '=')
		{
			if (name[j] != curr_env[j])
				match = 1;
			j++;
		}
		if (match == 0)
			return (environ[i]);
		i++;
	}

	return (NULL);
}
