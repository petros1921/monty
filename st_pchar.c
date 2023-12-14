#include "monty"

/**
 * st_pchar - Prints the char at the top of the stack, followed by a new line.
 * @entry: Pointer to the entry point of the stack.
 * @shelf: Line number.
 * By Kidus Yohannes and Petros Worku.
 */

void st_pchar(stack_t **entry, unsigned int shelf)
{
	stack_t *top = *entry;

	if (!top)
	{
		fprintf(stderr, "L%d: cannot pchar, stack empty\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: cannot pchar, value out of range\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}
