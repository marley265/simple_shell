#include "shell.h"
/**
 * bin_exit - Implementation of the exit builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 *
 * @info: Information about the shell
 * @arguments: Arguments received
 **/
void bin_exit(general_t *info, char **arguments)
{
	int status_code, status;

	status = _TRUE;
	if (arguments[1] != NULL)
		status = number_controller(info, arguments[1]);

	if (status == _FALSE)
		return;

	status_code = info->status_code;

	free_pointer((void *) info->buffer);
	free_pointer((void *) info->environment);
	free_pointer((void *) info);
	free_double_pointer((void **) arguments);

	exit(status_code);
}

/**
 * number_controller - Checks the exit arguments
 *
 * @info: General information about the shell
 * @number: The builtin argument passed
 *
 * Return: if arg is valid(_TRUE). Else(_FALSE)
 **/
int number_controller(general_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = ERROR_CODE_INVALID_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_number > 255)
		info->status_code = _number % 256;
	else
		info->status_code = _number;

	return (_TRUE);
}
