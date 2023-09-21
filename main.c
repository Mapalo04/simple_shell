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
	int num_tokens = 0, i, a;
	size_t n = 0;
	ssize_t nread_ch = 0;
	pid_t pid;
	struct stat buf;

	(void)ac;
	/* displays the shell over and over */
	while (nread_ch != -1)
	{
		a++;
		/* prints and gets the input from user */
		printf("$ ");
		nread_ch = getline(&lineptr, &n, stdin);
		/*custom_eof(&lineptr, nread_ch); /handle end of line*/
		num_tokens = path_form(lineptr, token, nread_ch);/*now we tokenize string*/
		argv = malloc(sizeof(char *) * num_tokens);
		if (argv == NULL)
			return (-1);
		token = strtok(lineptr, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		if (stat(get_path(argv[0]), &buf) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("hsh: Fork error");
				return (-1);
			}
			else if (pid == 0)
			{
				execmd(argv);
				for (i = 0; i < num_tokens; i++)
				{
					free(argv[i]);
				}
				/*free(argv);*/
			}
			else
				wait(NULL);
		}
	}
	/*if (lineptr != NULL)
		free(lineptr);*/
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
	strcpy(lineptr_copy, lineptr);
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
