#include "main.h"

int path_form(char *lineptr, char *token, ssize_t nreadch);

/**
 * main - Entry point of the program
 * @ac: the number of arguments
 * @argv: array of arguments.
 *
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *p = "$ ", *lineptr;
	char *delim = " \n", *token;
	int num_tokens = 0, i, pid;
	size_t n = 0;
	ssize_t nread_ch;

	(void)ac;
	/* displays the shell over and over */
	while (1)
	{
	pid = fork();
	if (pid == -1)
	{
		perror("Error... occurred");
		return (-1);
	}
	/* prints and gets the input from user */
	printf("%s", p);
	nread_ch = getline(&lineptr, &n, stdin);
	if (nread_ch == -1)
	{
		printf("Shell ......exited\n");
		return (-1);
	}

	/**
	 * makes a copy of the string and divides it into separate strings
	 * for command execution
	 */
	num_tokens = path_form(lineptr, token, nread_ch);

	/*allocates space to keep the array of strings*/
	argv = malloc(sizeof(char *) * num_tokens);
	if (argv == NULL)
		return (-1);
	token = strtok(lineptr, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	/* Executes the command */
	execmd(argv);
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
		perror("tsh: memory allocation error");
		return (-1);
	}
	_strcpy(lineptr_copy, lineptr);
	token = strtok(lineptr_copy, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	free(lineptr_copy);
	return (num_tokens);
}
