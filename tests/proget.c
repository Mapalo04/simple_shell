#include <string.h>
#include "main.h"
/**
 * main- Entry Point
 *
 * Return- 0, when successful
 */
int main(void)
{
	size_t n = BUF_SIZE;
	char *line = malloc(sizeof(char) * n);
	ssize_t read_line;
	char *tokens[BUF_SIZE];
	int my_tokens = 0;
	char *tok = NULL;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		read_line = my_getline(&line, &n, stdin);
		if (read_line == -1)
		{
			perror("getline error");
			break;
		}
		printf("%s\n", line);
		tok = cust_strtok(line, " ");
		while (tok != NULL)
		{
			printf("%s\n", tok);
			tok = cust_strtok(NULL, " ");
		}

	}
	free(line);
	return (0);
}
