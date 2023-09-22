#include "main.h"
/**
 * custom_eof- Handles the end of file
 * @val: Checks the value of getline
 * @buf: The given buffer
 *
 * Return: The given value of getline function
 */
void custom_eof(char **buf, ssize_t val)
{
	(void)buf;

	if (val == -1)
	{
		printf("\n");
		free(buf);
		exit(0);
	}
}
