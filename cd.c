#include "shell.h"
/**
 *bin_cd - Implementation of the cd inbuilt command
 *@info: Information about the shell (from general_t)
 *@arguments: the commands passed as arguments
 *Return: the status code
 */
void bin_cd(general_t *info, char **arguments)
{
	char *target_dir = arguments[1];
	int result;

	if (target_dir == NULL)
		target_dir = _getenv("HOME");

	result = chdir(target_dir);
	if (result == 0)
	{
		info->status_code = 0;
	}
	else
	{
		perror("cd");
		info->status_code = -1;
	}

	free_pointer((void *)info->environment);
	free_pointer((void *)info->buffer);
	free_double_pointer((void **)arguments);

;
}
