#include "main.h"

/**
 * _printf - prints a string
 * @str: the string to print
 *
 * Return: number of character
 */

int _printf(char *str)
{
	int i = 0;

	while (str[i] == '\0')
	{
		write(1, &str[i], 1);
		i++;

	}
	return (i);
}
