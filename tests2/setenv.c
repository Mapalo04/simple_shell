#include "main.h"
/**
 * unsetenv_builtin- Checks syntax and unsets the environmental variable
 * @arg: The arguments in the command
 *
 * Return: The unset variable, otherwise error
 */
void unsetenv_builtin(char **arg)
{
	if (arg[1] == NULL)/*This checks the syntax*/
	{
		write(2, "Unsetenv Variable\n", _strlen("Unsetenv Variable\n"));
		return;
	}
	if (unsetenv(arg[1]) != 0)/*if there are arguments*/
	{
		perror("hsh: unsetenv error");
		return;
	}
}
/**
 * setenv_builti- checks syntaxs then sets environ variable
 * @arg: The arguments
 *
 * Return: Set variable, otherwise error
 */
void setenv_builtin(char **arg)
{
	if (arg[2] == NULL || arg[1] == NULL)
	{
		write(2, "setenv VARIABLE\n", _strlen("setenv VARIABLE\n"));
		return;
	}
	if (setenv(arg[1], arg[2], 1) != 0)
	{
		perror("hsh: setenv error");
		return;
	}
}
