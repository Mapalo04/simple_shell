#include "main.h"
/**
 * main- Entry Point of shell Program
 *
 * Return: 0 when successful, otherwise -1 and perror
 */
int main(void)
{
	char cmd[MAX_SIZE];
	ssize_t byt = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
		byt = custom_getline(cmd, MAX_SIZE);

		if (byt == 0)
		{
			break;
		}
		exec_command(cmd);
	}
	return (0);
}
