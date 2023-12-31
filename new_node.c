#include "monty.h"

/**
 * new_node - Create a new node and push it onto the stack.
 * @entry: Pointer to the entry point of the stack.
 * @value: Value to be stored in the new node.
 * By Kidus Yohannes and Petros Worku.
 */

void new_node(stack_t **entry, int value)
{
	stack_t *new_node, *current_node;

	current_node = *entry;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);

	}
	if (current_node)

		current_node->prev = new_node;


	new_node->n = value;
	new_node->next = *entry;
	new_node->prev = NULL;

	*entry = new_node;
}
