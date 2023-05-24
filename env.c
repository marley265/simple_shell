#include "shell.h"
/**
 * bin_env - Implementation for the env builtin
 * @info: General information about the shell (from general_t)
 * @arguments: Command passed
 **/
void bin_env(general_t *info, char **arguments)
{
        (void) arguments;
        (void) info;

        get_full_env();
}
