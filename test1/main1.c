#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */

int main(void)
{
	char *lineptr, *token;
	size_t n = 0;
	ssize_t nread_ch = 0;
	char **args = NULL;
	int i = 0;
	pid_t pid;

	while (nread_ch != -1)
	{
		printf("$ ");
		nread_ch = getline(&lineptr, &n, stdin);

		if (nread_ch == -1)
		{
			printf("Shell is exiting\n");
			_exit(1);
			continue;
		}
		args = malloc(sizeof(char *) * 2);
		token = strtok(lineptr, " \n");
		i = 0;
		while (token)
		{
			args[i] = strdup(token);
			i++;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;
		if (nread_ch != -1){
		pid = fork();
		if (pid == -1)
			perror("hsh: fork error");
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("hsh: command not found");
		}
		else
			wait(NULL);
		}

	}

}
