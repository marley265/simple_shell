#include "shell.h"

/**
 *free_pointer - Free a (single) pointer allocated memory
 *@ptr: Pointer to free
 *Return: Nothing
 **/
void free_pointer(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_double_pointer - Free a double pointer allocated mem space
 *@ptr: Double pointer to free
 *Return: Nothing
 **/
void free_double_pointer(void **ptr)
{
	void **temp;

	for (temp = ptr; *temp != NULL; temp++)
		free_pointer(*temp);

	free_pointer(ptr);
}
