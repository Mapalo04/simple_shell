#include "main.h"
/**
 * custom_getline- Works the same as read or getline
 * @cmd: This is the command inputed
 * @max_size: This the largest size allocated to the input
 *
 * Return: The bytes read
 */
ssize_t custom_getline(char *cmd, size_t max_size)
{
	ssize_t byt;

	byt = read(STDIN_FILENO, cmd, max_size - 1);

	if (byt == 0)/*meaning end of file*/
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (byt == -1)
	{
		perror("hsh:getline error");
		exit(1);
	}
	else
	{
		cmd[byt] = '\0';
		if (cmd[byt - 1] == '\n')
		{
			cmd[byt - 1] = '\0';
		}
	}
	return (byt);
}
