#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t pmy_pid;

	my_pid = getpid();
	pmy_pid = getppid();
	printf("%u\n", my_pid);
	printf("%u\n", pmy_pid);
	return (0);
}
