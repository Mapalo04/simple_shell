#include "main.h"
/**
 * _strncmp- Compares strings to find their similarities
 * @str1: The first string
 * @str2: The second string
 * @n: The number of max char
 *
 * Return: 0 when successful
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t x;
	
	for (x = 0; x < n; x++)
	{
		if(str1[x] != str2[x])
		{
			return (int)(str1[x] - str2[x]);
		}
		if (str1[x] == '\0' || str2[x] == '\0')
		{
			break;
		}
	}
	return (0);
}
/**
 * _strchr- It searches characters of a string
 * @s: The string to be checked
 * @ch: the character we are looking for
 *
 * Return: The char, otherwise return
 */
const char* _strchr(const char *s, int ch)
{
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
