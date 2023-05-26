#include "shell.h"

/**
 * hsh_alias - Prints all or specific aliasesand sets a neew alias
 * @cmd: an array of aliases
 * Return: On success (0) ese (-1)
 */
int hsh_alias(char **cmd)
{
        alias_t *temp = aliases;
        int i, aux = 0;
        char *value;

        if (!cmd[0])
        {
                while (temp)
                {
                        print_alias(temp);
                        temp = temp->next;
                }
                return (aux);
        }
        for (i = 0; cmd[i]; i++)
        {
                temp = aliases;
                value = strchr(cmd[i], '=');
                if (!value)
                {
                        while (temp)
                        {
                                if (strcmp(cmd[i], temp->name) == 0)
                                {
                                        print_alias(temp);
                                        break;
                                }
                                temp = temp->next;
                        }
                        if (!temp)
                                perror("./hsh");
                }
                else
                        set_alias(cmd[i], value + 1);
        }
        return (aux);
}

/**
 *set_alias - sets existing alias name with a new value
 * or creates a new alias with a new name
 *@var_name: Alias name
 *@value: Value of se alias
 *Return: Nothing
 */
void set_alias(char *var_name, char *value)
{
        alias_t *temp = aliases;
        int k, j, len;
        char *new_value;

        *value = '\0';
        value++;
        len = strlen(value) - strspn(value, "'\"");
        new_value = malloc(sizeof(char) * (len + 1));
        if (!new_value)
                return;
        for (j = 0, k = 0; value[j]; j++)
        {
                if (value[j] != '\'' && value[j] != '"')
                        new_value[k++] = value[j];
        }
        new_value[k] = '\0';
        while (temp)
        {
                if (strcmp(var_name, temp->name) == 0)
                {
                        free(temp->value);
                        temp->value = new_value;
                        break;
                }
                temp = temp->next;
        }
        if (!temp)
                add_alias_end(&aliases, var_name, new_value);
}

/**
 *print_alias - prints aliases (name='value')
 *@alias:pointer to an alias.
 *Return: Nothing
 */
void print_alias(alias_t *alias)
{
        char *stralias;
        int len = strlen(alias->name) + strlen(alias->value) + 4;

        stralias = malloc(sizeof(char) * (len + 1));
        if (!stralias)
                return;
        strcpy(stralias, alias->name);
        strcat(stralias, "='");
        strcat(stralias, alias->value);
        strcat(stralias, "'\n");

        write(STDOUT_FILENO, stralias, len);
        free(stralias);
}

/**
 *replace_aliases - replaces any matching aliases with their value
 *@cmd: pointer to the arguments
 *Return: cmd
 */
char **replace_aliases(char **cmd)
{
        alias_t *temp;
        int i;
        char *new_value;

        if (strcmp(cmd[0], "alias") == 0)
                return (cmd);
        for (i = 0; cmd[i]; i++)
        {
                temp = aliases;
                while (temp)
                {
                        if (strcmp(cmd[i], temp->name) == 0)
                        {
                                new_value = malloc(sizeof(char) *
                                                   (strlen(temp->value) + 1));
                                if (!new_value)
                                        return (NULL);
                                strcpy(new_value, temp->value);
                                free(cmd[i]);
                                cmd[i] = new_value;
                                break;
                        }
                        temp = temp->next;
                }
        }
        return (cmd);
}
