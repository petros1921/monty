#include "monty.h"

/**
 * st_swap - Swap the top two elements of the stack.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohanes and Petros Worku.
 */

void st_swap(stack_t **entry, unsigned int shelf)
{
	stack_t *top_node;
	int len = 0, aux;

	top_node = *entry;
	while (top_node)
	{
		top_node = top_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: cannot swap, stack is to short\n", shelf);
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}

	top_node = *entry;
	aux = top_node->n;
	top_node->n = top_node->next->n;
	top_node->next->n = aux;
}