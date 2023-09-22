#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void execmd(char **args);
char  **tokenf(char *lineptr, int *n);

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */

int main(void)
{
	char *lineptr;
	size_t n = 0;
	ssize_t nread_ch = 0;
	char **args = NULL;
	int i = 0, a;

	while (1)
	{
		printf("$ ");
		nread_ch = getline(&lineptr, &n, stdin);

		if (nread_ch == -1)
		{
			printf("Shell is exiting\n");
			_exit(0);
			continue;
		}
		args = tokenf(lineptr, &i);
		
		execmd(args);
		for (a = 0; a < i; a++)
			free(args[i]);
		free(args);

	}
}

char  **tokenf(char *lineptr, int *n)
{
	char **args = NULL, *token, *del = " \n";

	args = malloc(sizeof(char *) * 2);
	token = strtok(lineptr, " \n");
	*n = 0;
	while (token)
	{
		args[*n] = strdup(token);
		*n = *n + 1;
		token = strtok(NULL, del);
	}
	args[*n] = NULL;

	return (args);
}

/**
 * execmd - executes commands
 * @args: list of arguments
 */

void execmd(char **args)
{
	pid_t pid;
		
	pid = fork();
	if (pid == -1)
	{
		printf("hsh: fork error");
		return;
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("hsh: command not found");
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}

		
}
