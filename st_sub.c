#include "monty.h"

/**
 * st_sub - Subtract the top element from the second top element of the stack.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohannes and Petros Worku.
 */

void st_sub(stack_t **entry, unsigned int shelf)
{
	stack_t *top_node;
	int count = 0, result;

	top_node = *entry;
	while (top_node)
	{
		top_node = top_node->next;
		count++;
	}
	if (count < 2)
	{
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	top_node = *entry;
	result = top_node->next->n - top_node->n;
	top_node->next->n = result;
	*entry = top_node->next;
	free(top_node);
}
