#include "monty.h"

/**
 * new_queue - Create a new node and enqueue it.
 * @entry: Pointer to the entry point of the stack or queue.
 * @value: Value to be stored in the new node.
 * By Kidus Yohannes and Petros Worku.
 */
void new_queue(stack_t **entry, int value)
{
	stack_t *new_queue_node, *current_node;

	current_node = *entry;
	new_queue_node = malloc(sizeof(stack_t));

	if (new_queue_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new queue node\n");
		exit(EXIT_FAILURE);
	}
	new_queue_node->n = value;
	new_queue_node->next = NULL;

	if (current_node)
	{
		while (current_node->next)
		{
			current_node = current_node->next;
		}
	}

	if (!current_node)
	{
		*entry = new_queue_node;
		new_queue_node->prev = NULL;
	}
	else
	{
		current_node->next = new_queue_node;
		new_queue_node->prev = current_node;
	}
}
