#include "main.h"
/**
 * handle_mycommands- Handles all built in commands
 * @tok: The string tokens
 *
 * Return: The command
 */
void handle_mycommands(char **tok)
{
	if (_strncmp(tok[0], "setenv", 6) == 0)
	{
		setenv_builtin(tok);
	}
	else if (_strncmp(tok[0], "unsetenv", 8) == 0)
	{
		unsetenv_builtin(tok);
	}
	else if (_strncmp(tok[0], "exit", 4) == 0)
	{
		builtin_exit(tok);
	}
	else if (_strncmp(tok[0], "cd", 2) == 0)
	{
		builtin_cd(tok);
	}
	else if (_strncmp(tok[0], "env", 3) == 0)
	{
		builtin_env(tok);
	}
	else
	{
		printf("command not found");
	}
}
