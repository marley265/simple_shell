#include "shell.h"
/**
 * prompt - Print the shell prompt
 * @info: Struct of general shell information
 *Return: Nothing
 **/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print("$ ");
}

/**
 * read_prompt - reads the command passed to the shell
 * Return: Buffer read or NULL if EOF was found
 **/
char *read_prompt()
{
	char *buffer;

	buffer = _getline();

	if (buffer == NULL)
	{
		free_pointer((void *) buffer);
		return (NULL);
	}

	return (buffer);
}

/**
 * start_prompt - Loops through the text, reading each line
 * @info: Struct of general shell information
 * Return: Read buffer
 **/
void start_prompt(general_t *info)
{
	char *buff;
	char **arguments;
	char *path;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(info);

		path = _getenv("PATH");
		is_current_path(path, info);

		info->environment = path;
		buff = read_prompt();
		if (buff == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}

		info->n_commands++;
		if (buff[0] != '\n')
		{
			arguments = split_words(buff, " \t\n");

			info->arguments = arguments;
			info->buffer = buff;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buff);

			free_double_pointer((void *) arguments);
		}

		free_pointer((void *) buff);
		free_pointer((void *) path);
	}

}

/**
 * sigintHandler - Handler for SIGINT
 * @sig_num: assigned signal number
 *Return: Nothing
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
