#include "monty.h"

/**
 * st_add - Add the top two elements of the stack.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohannes and Petros Worku.
 */

void st_add(stack_t **entry, unsigned int shelf)
{
	stack_t *top_node;
	int count = 0, sum;

	top_node = *entry;
	while (top_node)
	{
		top_node = top_node->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: cannot add, stack too short\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	top_node = *entry;
	sum = top_node->n + top_node->next->n;
	top_node->next->n = sum;
	*entry = top+node->next;
	free(top_node);
}
