#include "monty.h"

/**
 * st_pop - Remove the top element from the stack.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohannes and Petros Worku.
 */

void st_pop(stack_t **entry, unsigned int shelf)
{
	stack_t *top_node;

	if (*entry == NULL)
	{
		fprintf(stderr, "L%d: cannot pop an empty stack\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	top_node = *entry;
	*entry = top_node->next;
	free(top_node);
}
