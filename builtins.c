#include "shell.h"

/**
 * builtins - Check and execute the builtins
 * @info: Information about the shell
 * @arguments: Commands passed as arguments
 * Return: if command is builtin (_TRUE) else (_FALSE)
 **/
int builtins(general_t *info, char **arguments)
{
	int status;

	status = check_builtin(info, arguments);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}


/**
 * check_builtin - Checks if passed command is an inbuilt command
 * @info: Contains general shell info. (from general_t)
 * @arguments: Arguments of the passed command
 * Return: if command is builtin (_TRUE) else (_FALSE)
 **/
int check_builtin(general_t *info, char **arguments)
{
	int i, size;
	builtin_t builtins[] = {
		{"exit", bin_exit},
		{"env", bin_env},
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[i].func(info, arguments);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
