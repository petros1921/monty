#include "monty.h"

/**
 * st_div_op - Divides the top two elements of the stack.
 * @entry: Double pointer to the stack head.
 * @shelf: Line number.
 * Return: No return value.
 * By Kidus Yohannes and Petros Worku.
 */

void st_div_op(stack_t **entry, unsigned int shelf)
{
	stack_t *s;
	int count = 0, div_result;

	s = *entry;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: cannot div, stack too short\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	s = *entry;
	if (s->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}

	div_result = s->next->n / s->n;
	s->next->n = div_result;
	*entry = s->next;
	free(s);
}
