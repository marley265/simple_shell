#include "shell.h"

/**
 *_realloc - reallocates a memory block using malloc and free
 *@ptr: current pointer address
 *@old_size: allocated space for ptr
 *@new_size: size in bytes of the new memory block
 *Return: reallocated space (new)
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *new, *aux;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
			return (NULL);

		return (new);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);

	aux = ptr;
	for (i = 0; i < old_size; i++)
		new[i] = aux[i];

	free(ptr);

	return (new);
}
