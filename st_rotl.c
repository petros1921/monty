#include "monty.h"

/**
 * st_rotl - Rotate the stack to the top.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohannes and Petros Worku.
 */

void st_rotl(stack_t **entry, unsigned int shelf)
{
	stack_t *top_node = *entry, *new_top;

	if (*entry == NULL || (*entry)->next == NULL)
	{
		return;
	}

	new_top = (*entry)->next;
	new_top->prev = NULL;
	while (top_node-> next != NULL)
	{
		top_node = top_node->next;
	}
	top_node->next == *entry;
	(*entry)->next = NULL;
	(*entry)->prev = top_node;
	*entry = new_top;
}
