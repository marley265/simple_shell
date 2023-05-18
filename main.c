#include "shell.h"
/**
 *main - simple_shell entry point
 *@ac: Number of arguments passed to main
 *@av: list of the passed arguments
 *Return: Exit
 */
int main(int ac, char **av)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		printf("# ");
		line = command();
		args = tokenize(line);
		status = execute (args);

		free(line);
		free(args);
	}
}
