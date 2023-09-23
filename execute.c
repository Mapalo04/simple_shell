#include "main.h"
/**
 * _execute- Executes commands
 * @argc: The input the user has
 *
 * Return: Executed command or error
 */
void _execute(char *argc)
{
	int arg_count = 0;
	char *input[MAX_SIZE];
	char *token = cust_strtok(argc, " ");

	while (token != NULL)
	{
		input[arg_count] = token;
		arg_count++;
		token = cust_strtok(NULL, " ");
	}
	input[arg_count] = NULL;
	if (execve(input[0], input, NULL) == -1)
	{
		perror("hsh: Execution Failure");
		exit(1);
	}
}
/**
 * exec_command- Function that executes commands
 * @cmd: The command
 *
 * Return: Executed command
 */
void exec_command(char *cmd)
{
	int status = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("hsh: Fork error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		_execute(cmd);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
