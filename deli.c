#include "main.h"
/**
 * cust_strtok- Works the same as strtok to split strings
 * @command: The command user inputs
 * @del: The split string
 *
 * Return: Split string
 */
char *cust_strtok(char *command, const char *del)
{
	char *begin_token; /*where the string command starts*/
	static char *end_token;/*the last string*/
	/*bool is_delim = true;*/

	if (command != NULL)
	{
		end_token = command;
	}
	while (*end_token && _strchr(del, *end_token))
	{
		end_token++;
	}
	if (*end_token == '\0')
	{
		return (NULL);
	}
	begin_token = end_token;
	while (*end_token && !_strchr(del, *end_token))
	{
		end_token++;
	}
	if (*end_token)
	{
		*end_token = '\0';
		end_token++;
	}
	return (begin_token);
}

