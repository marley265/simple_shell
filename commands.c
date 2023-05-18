#include "shell.h"
/**
 *command - reads the line from the stdio
 *@buffer: allocaated space for each command entered
 *@positon: the position of each command in line
 *Returns: line
 */
char *command(char *line, ssize_t bufsize)
{
	line = NULL;
	bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (*line);
}
