#include "monty.h"

/**
 * stack_remover - Remove all nodes from a stack.
 * @entry: Pointer to the entry point of the stack.
 *
 */
void stack_remover(stack_t *entry)
{
	stack_t *current_node;

	current_node = entry;
	while (entry)
	{
		current_node = entry->next;
		free(entry);
		entry = current_node;
	}
}
