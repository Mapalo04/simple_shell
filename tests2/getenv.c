#include "main.h"
/**
 * my_getenv- This is a custom getenv that searches env variables
 * @nm: The env var name to be searched
 *
 * Return: The env variable, otherwise error
 */
char *my_getenv(const char *nm)
{
	char **var_env;
	size_t nm_length = 0;

	/*environ comes from char extern environ*/
	if (environ == NULL || nm == NULL)
	{
		return (NULL);
	}
	nm_length = _strlen((char *)nm);/*calculates the length of environ*/
	for (var_env = environ; *var_env != NULL; var_env++)
	{/*Then we compare if nm is same as **var_env using strncmp*/
		if (_strncmp(nm, *var_env, nm_length) == 0 && (*var_env)[nm_length] == '=')
		{/*afterwards it checks if it has an = to show variable assignment value*/
			return (1 + *var_env + nm_length);
		}
	}
	return (NULL);
}
