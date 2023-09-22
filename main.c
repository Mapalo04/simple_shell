#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 100

int main(void)
{
	char cmd[MAX_INPUT_SIZE];
	int byt, status;
	pid_t child_pid;
	char *argv[] = {NULL, NULL};
	
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		byt = read(STDIN_FILENO, cmd, MAX_INPUT_SIZE);
		if (byt == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		else if (byt == -1)
		{
			perror("read");
			exit(1);
		}
		cmd[byt] = '\0';
		if (cmd[byt - 1] == '\n')
		{
			cmd[byt - 1] = '\0';
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (child_pid == 0)
		{
			argv[0] = cmd;
			argv[1] = NULL;
			if (execve(cmd, argv, NULL) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	return (0);
}
