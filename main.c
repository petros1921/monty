#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>

MontyContext_t monty_con = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	stack_t *entry = NULL;
	size_t line_size = 0, read_line = 1;
	char *line_content;
	FILE *file;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	monty_con.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &line_size, file);
		monty_con.file_content = line_content;
		line_number++;

		if (read_line > 0)
		{
			execute_bytecode(line_content, &entry, line_number, file);
		}
		free(line_content);
	}
	stack_remover(entry);
	fclose(file);

	return (0);
}
