#include "shell.h"
/**
 * _getenv - Get the environment variable
 * @name: Environment variable to get
 * Return: On success (value of name) else (NULL)
 **/
char *_getenv(const char *name)
{
	char **env = environ;
	char *temp;
	char *token;
	char *value;
	int size;

	size = _strlen((char *) name);

	for (; *env; ++env)
	{
		temp = _strdup(*env);

		token = strtok(temp, "=");
		if (token == NULL)
		{
			free(temp);
			return (NULL);
		}

		if (_strlen(token) != size)
		{
			free(temp);
			continue;
		}

		if (_strcmp((char *) name, temp) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(temp);
			return (value);
		}

		free(temp);
	}

	return (NULL);
}

/**
 * which - Finds the requested directory
 * @filename: Command received
 * @info: General info about the shell (from general_t)
 * Return: on success (string pointer to reqested path) else (NULL)
 */
char *which(char *filename, general_t *info)
{
	char *path;
	char *temp_path;
	char *token;
	char *slash;
	int size;

	(void) info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	size = _strlen(filename) + 2;
	slash = malloc(size * sizeof(char));
	slash = _strcpy(slash, "/");
	slash = _strcat(slash, filename);

	while (token != NULL)
	{
		temp_path = malloc(_strlen(token) + size);
		temp_path = _strcpy(temp_path, token);
		temp_path = _strcat(temp_path, slash);

		if (is_executable(temp_path) == PERMISSIONS)
		{
			free(slash);
			free(path);
			return (temp_path);
		}
		token = strtok(NULL, ":");

		free(temp_path);
	}

	free(path);
	free(slash);

	return (NULL);
}

/**
 * is_current_path - checks and gives the current path
 * @path: PATH to check
 * @info: General information about the shell (from general_t)
 *Return: Nothing
 **/
void is_current_path(char *path, general_t *info)
{
	info->is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		info->is_current_path = _TRUE;
}

/**
 * get_full_env - returns the full path
 *Return: Nothing
 **/
void get_full_env(void)
{
	char **temp = environ;
	int i;

	for (i = 0; temp[i] != NULL; i++)
	{
		print(temp[i]);
		_putchar('\n');
	}
}
