#include "shell.h"
/**
 *_printerror - prints an error message to STDERR
 *@msg: the mesage to print
 *Return: Number of printed bytes
 */
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}
