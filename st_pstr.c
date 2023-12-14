#include "monty.h"

/**
 * st_pstr - Prints the string starting at the top of the stack, followed by a newline.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohannes Petros Worku.
 */

void st_pstr(stack_t **entry, unsigned int shelf)
{
	stack_t *top = *entry;
	(void)shelf;

	while (top)
	{
		if (top->n > 127 || top->n <= 0 || !isprint(top->n))
		{
			break;
		}
		putchar(top->n);
		top = top->next;
	}
	putchar("\n");
}
