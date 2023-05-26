#include "shell.h"
/**
 *_getline - reads input line from STDIN
 *@bufsize: total space to hold read characters
 *@i: the position of the line from STDIN
 *Return: Nothing
 */
char *_getline(void)
{
	int i;
	char c;
	char *buffer;
	int bufsize = LINE_BUFSIZE;

	buffer = malloc(sizeof(char) * bufsize);

	i = 0;
	if (!buffer)
	{
		perror("./hsh\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[i] = '\0';
			return (buffer);
		}
		else
		{
			buffer[i] = c;
		}
		i++;

		if (i >= bufsize)
		{
			bufsize += LINE_BUFSIZE;
			buffer = realloc(buffer, sizeof(char) * bufsize);
			if (!buffer)
			{
				exit(EXIT_FAILURE);
			}
		}
	}
}
