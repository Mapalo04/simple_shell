#include "main.h"
/**
 * my_getline- This works as a custom getline
 * @lptr: This is a line pointer
 * @mag: The byte size of the line to be read
 * @stream: The file types, stdin, stdout, or stderr
 *
 * Return: The line to be read, otherwise -1
 */

char *my_getline(char *lptr, size_t *mag, FILE *stream)
{
	static char buf[BUF_SIZE];
	static size_t buf_sz;
	static size_t buf_place;
	size_t i = 0;
	char m;

	while (i < (*mag) - 1)
	{
		if (buf_place == buf_sz)
		{
			buf_sz = read(fileno(stream), buf, BUF_SIZE);
			if (buf_sz == 0)
			{
				break;
			}
		buf_place = 0;
		}
		m = buf[buf_place++];
		if (m == '\n')
		{
			break;
		}
		lptr[i++] = m;
	}
	lptr[i] = '\0';
	return (lptr);
}

