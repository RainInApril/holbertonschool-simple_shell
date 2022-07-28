#include "main.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: the string being checked
 * Return: returns the length of a string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: string to be compared
 * @s2: another string to be compared
 * Return:  0 if the strings are the same, else if different
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i = i + 1;
	}
		return (0);
}

/**
 * _strdup -  returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: the pointer to the string
 * Return: returns a pointer
 */

char *_strdup(const char *str)
{
	char *dest;
	int i, j;

	if (str == NULL)
		return (NULL);

	i = _strlen(str);

	dest = malloc(sizeof(*dest) * (i + 1));
	if (dest == NULL)
		return (NULL);

	j = 0;
	while (str[j] != '\0')
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';

	return (dest);
}
