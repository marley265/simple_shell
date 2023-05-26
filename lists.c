#include "shell.h"
/**
 *add_alias_end - adds a new node at the end of a alias_t linked list
 *@head: A pointer to the head of list_t
 *@name: The name of the new alias
 *@value: new alias to be added
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free_pointer(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
/**
 *add_node_end - adds  a node at the end of a list_t
 *@head: Pointer to the head of the list_t
 *@dir: path directory to be added to the new node
 *Return: pointer to the new node
 */
struct list_s *add_node_end(list_t **head, char *dir)
{
	struct list_s *new_node = malloc(sizeof(struct list_s));
	struct list_s *last = NULL;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
/**
 *free_alias_list - frees the alias_t linked lists
 *@head: Head of the alias_t list
 *Return: Nothing
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}
/**
 *free_list - frees a linked list
 *@head: head of the linked list
 *Return: Nothing
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
