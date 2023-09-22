#include "main.h"

/**
 * get_path - gets the path of the command
 * @cmd: the command
 *
 * Return: path
 */

char *get_path(char *cmd)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
	path_copy = strdup(path);
	cmd_length = strlen(cmd);
	path_token = strtok(path_copy, ":");
	while (path_token)
	{
		directory_length = strlen(path_token);
		file_path = malloc(cmd_length + directory_length + 2);
		/* The Path for the command, by copying the command and pasting to it */
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");

		/* checks if the file path actually exists */
		if (stat(file_path, &buffer) == 0)
		{
			/*free(path_copy);*/
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	/*free(path_copy);*/
	/* check if the command */
	if (stat(path, &buffer) != 0)
		return (cmd);
	return (NULL);
	}
	return (NULL);
}
