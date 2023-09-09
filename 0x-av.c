#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @ac: the number of arguments
 * @av: array of arguments.
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	int i = 0;

	(void) ac;
	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
}
