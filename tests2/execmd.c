#include "main.h"

/**
 * execmd - executes programs
 * @argv: an array of arguments for command
 *
 */

void execmd(char **argv)
{
	char *cmd = NULL, *command = NULL;

	if (argv)
	{
		cmd = argv[0];
		command = get_path(cmd);
		if (execve(command, argv, NULL) == -1)
		{
			perror("hsh: Error");
		}
	}

}
