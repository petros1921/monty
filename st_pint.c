#include "monty.h"

/**
 * st_pint - Prints the value at the top of the stack.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * BY Kidus Yohannes and Petros Worku.
 */
void st_pint(stack_t **entry, unsigned int shelf)
{
	if (*entry == NULL)
	{
	fprintf(stderr, "L%d: can't pint, stack empty\n", shelf);
	fclose(monty_con.file);
	free(monty_con.file_content);
	stack_remover(*entry);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*entry)->n);
}

