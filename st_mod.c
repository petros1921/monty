#include "monry.h"

/**
 * st_mod - Computes the rest of the division of the second top element of the stack by the top element of the stack.
 * @entry: Double pointer to the stack head
 * @shelf: Line number
 * Return: No return value
 * By Kidus Yohannes and Petros Worku.
 */

void st_mod(stack_t **entry, unsigned int shelf)
{
	stack_t *s;
	int count = 0, mod_result;

	s = *entry;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: cannot mod, stack too short\n", shelf);
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

	mod_result = s->next->n % s->n;
	s->next->n = mod_result;
	*entry = s->next;
	free(s);
}
