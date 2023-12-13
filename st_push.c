#include "monty.h"

void st_push(stack_t **entry, unsigned int shelf)
{
	int value, index = 0, invalid = 0;

	if (monty_con.argument)
	{
		if (monty_con.argument[0] == '-')
			index++;

		for (; monty_con.argument[index] != '\0'; index++)
		{
	if (monty_con.argument[index] > 57 || monty_con.argument[index] < 48)
		invalid = 1;
		}

		if (invalid == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", shelf);
			fclose(monty_con.file);
			free(monty_con.file_content);
			stack_remover(*entry);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", shelf);
		fclose(monty_con.file);
		free(monty_con.file_content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}
	value = atoi(monty_con.argument);
	if (monty_con.last_in_first_out == 0)
		new_node(entry, value);
	else
		new_queue(entry, value);
}

