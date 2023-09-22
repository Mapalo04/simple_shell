#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of the string.
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * _strcpy - copies a string src to dest
 * @dest: copying to
 * @src: copying from
 *
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (*(src + a) != '\0')
		a++;
	while (b < a)
	{
		dest[b] = src[b];
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strdup - duplicates a string.
 * @s: string to duplicate
 *
 * Return: duplicated string
 */

char *_strdup(char *s)
{
	char *dup = NULL;
	int a = 0, len = 0;

	while (s[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (a <= len)
	{
		dup[a] = s[a];
		a++;
	}
	
	return (dup);
}
/**
 * _strcat - concatenates two strings
 * @dest: holds result
 * @src: string to concatenate to
 *
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len1 = 0, len2 = 0;

	while (dest[len1] != '\0')
		len1++;
	while (src[len2] != '\0')
	{
		dest[len1] = src[len2];
		len1++;
		len2++;
	}
	dest[len1] = '\0';
	return (dest);
}
