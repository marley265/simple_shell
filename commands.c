#include "shell.h"
/**
 * analyze - checks if the shell should run in interactive
 *or non-interactive mode
 * @arguments: Commands to execute
 * @info: General information about the shell (from general_t)
 * @buff: Line readed
 *Return: Nothing
 **/
void analyze(char **arguments, general_t *info, char *buff)
{
	char *cmd;
	int status;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmd = arguments[0];
	info->command = cmd;
	if (check_builtin(info, arguments) == _TRUE)
		return;

	status = is_file(cmd);
	if (status == NON_PERMISSIONS)
	{
		info->status_code = 126;
		info->error_code = ERROR_CODE_PERMISSION;
		error(info);
		return;
	}

	if (status == 1)
	{
		execute(cmd, arguments, info, buff);
		return;
	}

	if (current_directory(cmd, arguments, buff, info) == _TRUE)
		return;
	info->value_path = which(cmd);
	if (info->value_path != NULL)
	{
		execute(info->value_path, arguments, info, buff);
		free(info->value_path);
		return;
	}
	info->status_code = 127;
	info->error_code = ERROR_CODE_CMD_NOT_FOUND;
	error(info);
}
