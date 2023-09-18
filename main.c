#include "main.h"

/**
 * main - Entry point of the program
 * @ac: the number of arguments
 * @av: array of arguments.
 *
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *p = "$ ", *lineptr, *lineptr_copy = NULL;
	char *delim = " \n", *token;
	int num_tokens = 0, i;
	size_t n = 0;
	ssize_t nread_ch;

	(void)ac;
	/* displays the shell over and over */
	while (1)
	{
	/* prints and gets the input from user */	
	printf("%s", p);
	nread_ch = getline(&lineptr, &n, stdin);
	if (nread_ch == -1){
		printf("Shell ......exited\n");
		return (-1);
	}

	/* makes a copy of the string and divides it into separate strings
	 * for command execution
	 */
	lineptr_copy = malloc(sizeof(char) * nread_ch);
	if (lineptr_copy == NULL){
		perror("tsh: memory allocation error");
		return (-1);
	}
	strcpy(lineptr_copy, lineptr);
	token = strtok(lineptr, delim);

	while (token != NULL){
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	/*allocates space to keep the array of strings*/
	argv = malloc(sizeof(char *) * num_tokens);
	if (argv == NULL)
		return (-1);
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	/* Executes the command */
	execmd(argv);

	}
	free(argv);
	free(lineptr);
	free(lineptr_copy);

	return (0);

}
