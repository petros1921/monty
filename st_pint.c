#include "monty.h"

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

