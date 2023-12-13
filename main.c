#include "monty.h"

MontyContext_t monty_con = {NULL, NULL, NULL, 0};

int main(void)
{
	stack_t *entry = NULL;

	st_push(&entry, 1);
	st_push(&entry, 2);
	st_push(&entry, 3);

	st_pall(&entry, 0);

	while (entry != NULL)
	{
		stack_t *temp = entry;
		entry = entry->next;
		free(temp);
	}
	return 0;
}
