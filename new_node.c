#include "monty.h"

void new_node(stack_t **entry, int value)
{
	stack_t *new_node, *current_node;

	current_node = *entry;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new node\n");
		exit(EXIT_FAILURE);

	}
	if (current_node != NULL)
	{
		current_node->prev = new_node;
	}

	new_node->n = value;
	new_node->next = *entry;
	new_node->prev = NULL;

	*entry = new_node;
}
