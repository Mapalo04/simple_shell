#include "main.h"
/**
 * main - Entry point of the program
 * @ac: the number of arguments
 * @argv: array of arguments.
 *
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *lineptr;
	char *delim = " \n", *token;
	int num_tokens = 0, i;
	size_t n = 0;
	ssize_t nread_ch;
	pid_t pid;

	(void)ac;
	/* displays the shell over and over */
	while (1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("hsh: Fork error");
			return (-1);
		}
		else if (pid == 0)
		{
			/* prints and gets the input from user */
			printf("$ ");
			nread_ch = getline(&lineptr, &n, stdin);
			if (nread_ch == -1 || nread_ch == EOF)
			{
				printf("shell exited\n");
				exit(0);
				return (-1);
			}
			/**
			 * makes a copy of the string and divides it into separate strings
			 * for command execution
			 * */
			num_tokens = path_form(lineptr, token, nread_ch);
			argv = malloc(sizeof(char *) * num_tokens);
			if (argv == NULL)
				return (-1);
			
			token = cust_strtok(lineptr, delim);
			for (i = 0; token != NULL; i++)
			{
				argv[i] = malloc(sizeof(char) * _strlen(token));
				_strcpy(argv[i], token);
				token = cust_strtok(NULL, delim);
			}
			argv[i] = NULL;
			execmd(argv);
		}
		else
			wait(NULL);
	}
	free(argv);
	free(lineptr);
	return (0);
}

/**
 * path_form - makes a proper path for the command
 * @lineptr: points to the string containing user input
 * @token: the token to keep the command to be formed
 * @nreadch: number of read character
 *
 * Return: number of tokens
 */


int path_form(char *lineptr, char *token, ssize_t nreadch)
{
	char *lineptr_copy = NULL, *delim = " \n";
	int num_tokens = 0;

	lineptr_copy = malloc(sizeof(char) * nreadch);
	if (lineptr_copy == NULL)
	{
		perror("hsh: memory allocation error");
		return (-1);
	}
	_strcpy(lineptr_copy, lineptr);
	token = cust_strtok(lineptr_copy, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = cust_strtok(NULL, delim);
	}
	num_tokens++;
	free(lineptr_copy);
	return (num_tokens);
}
