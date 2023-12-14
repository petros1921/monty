#include "monty.h"

MontyContext_t monty_con = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	stack_t *entry = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <bytecode_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	monty_con.file = fopen(argv[1], "r");
	if (monty_con.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	monty_con.file_content = read_file_content(monty_con.file);
	if (monty_con.file_content == NULL)
	{
		fclose(monty_con.file);
		fprintf(stderr, "Error: Unable to read file content\n");
		return EXIT_FAILURE;
	}
	monty_con.last_in_first_out = 0;

	execute_bytecode(&entry);
	 st_pall(&entry, 0);

	 fclose(monty_con.file);
	 free(monty_con.file_content);
	  stack_remover(entry);

	  return EXIT_SUCCESS;
}

