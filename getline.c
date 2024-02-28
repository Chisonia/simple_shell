#include "shell.h"
/**
 * read_command - reads command given by the user
 *
 * Return: cmdptr
 */
char *read_command()
{
	char *cmdptr = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&cmdptr, &len, stdin);
	if (read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	cmdptr[strcspn(cmdptr, "\n")] = 0;
	return (cmdptr);
}
