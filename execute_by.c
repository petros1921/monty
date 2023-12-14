#include "monty.h"

void execute_bytecode(stack_t **entry)
{
	char *token;
	const char delimiters[] = " \t\n";
	const char *opcode;
	int value;

	token = strtok(monty_con.file_content, delimiters);
	while (token != NULL)
	{
		opcode = token;

		token = strtok(NULL, delimiters);
		if (token != NULL)
		{
			value = atoi(token);
		}
		else
		{
			value = 0;
		}

		if (strcmp(opcode, "push") == 0)
		{
			st_push(entry, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			st_pall(entry, 0);
		}

		token = strtok(NULL, delimiters);
	}
}
