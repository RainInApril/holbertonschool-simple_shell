#include "main.h"

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


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src == NULL || *src == '\0')
		return (NULL);
	/*Copy while check for null operator*/
	while (src[i] != '\0')
	{
		/*Assign the value of each index*/
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - copy the string from src and concatenate it onto dest
 * @dest: dest pointer
 * @src: src pointer
 *Return: char
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, len;

	if (dest == NULL)
		return (NULL);

	if (src == NULL || *src == '\0')
		return (dest);

	len = _strlen(dest);
	/*Copy while check for null operator*/
	while (src[i] != '\0')
	{
		/*Assign the value of each index*/
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
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

	dest = malloc((sizeof(char) * i) + 1);
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
