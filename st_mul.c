#include "monty.h"

/**
 * st_mul - Multiplies the top two elements of the stack.
 * @entry: Double pointer to the stack head.
 * @shelf: Line number.
 * Return: No return value.
 * By Kidus Yohannes and Petros Worku.
 */

void st_mul(stack_t **entry, unsigned int shelf)
{
	stack_t *s;
	int count = 0, mul_result;

	s = *entry;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "l%d: cannot mul, stack too short\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		free_stack(*entry);
		exit(EXIT_FAILURE);
	}

	s = *entry;
	mul_result = s->next->n * s->n;
	s->next->n = mul_result;
	*entry = s->next;
	free(s);
}
