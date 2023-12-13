#include "monty.h"

void st_pall(stack_t **entry, unsigned int shelf)
{
	stack_t *node_pointer;
	(void)shelf;

	node_pointer = *entry;
	if (node_pointer == NULL)
		return;
	while (node_pointer)
	{
		printf("%d\n", node_pointer->n);
		node_pointer = node_pointer->next;
	}
}
