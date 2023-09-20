#include "main.h"
/**
 * builtin_exit- Exits the shell
 * @arg: The argument
 *
 * Description: Retunrs exit 0
 */
void builtin_exit(char **arg)
{
	(void)(arg);
	printf("You are leaving the simple shell\n");
	exit(0);
}
/**
 * builtin_env- Prints the current environment
 * @arg: The argument
 *
 * Return: The name of environment
 */
void builtin_env(char **env)
{
	int i; /*The environment variable*/

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
/**
 * builtin_cd- Acts as the function cd to change directory
 * @arg: The arguments
 *
 * Return: The changed directory user wants
 */
void builtin_cd(char **arg)
{
	char *cd_dir = NULL;
	char *ev_ag[] = {NULL, NULL, NULL};

	if (arg[1] == NULL)/*if there is no argument*/
	{
		cd_dir = my_getenv("HOME");
	}
	else if (arg[1][0] == '-')/*checks if it is cd -*/
	{
		cd_dir = my_getenv("OLDPWD");
	}
	else
	{
		cd_dir = arg[1];
	}
	if (access(cd_dir, F_OK) != 0)
	{
		perror("hsh: Directory does not exist");
		return;
	}
	if (chdir(cd_dir) != 0)
	{
		perror("hsh: chdir error");
		return;
	}
	ev_ag[0] = "PWD";
	ev_ag[1] = getcwd(NULL, 0);
	ev_ag[2] = NULL;
	setenv_builtin(ev_ag);
}
