#include "monty.h"

/**
 * execute_bytecode - Execute bytecode instructions.
 * @entry: Pointer to the entry point of the stack.
 * By Kidus Yohannes and Petros Worku.
 *
 */

int execute_bytecode(char *content, stack_t **entry, unsigned int line_number, FILE *file)
{
	instruction_t instructions[] = {
		{"push", st_push},
		{"pall", st_pall},
		{"pop", st_pop},
		{"pint", st_pint},
		{NULL, NULL}
	};

	unsigned int index = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	monty_con.argument = strtok(NULL, " \n\t");

	while (instructions[index].opcode && opcode)
	{
		if (strcmp(opcode, instructions[index].opcode) == 0)
		{
			instructions[index].f(entry, line_number);
			return (0);
		}
		index++;
	}

	if (opcode && instructions[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		stack_remover(*entry);
		exit(EXIT_FAILURE);
	}
	return (1);
}
