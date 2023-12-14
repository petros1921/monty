#include "monty.h"

char *read_file_content(FILE *file)
{
	size_t length;
	char *content = NULL;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Invalid file pointer\n");
		exit(EXIT_FAILURE);
	}

	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);

	content = (char *)malloc(length + 1);
	if (content == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (fread(content, 1, length, file) != length)
	{
		fprintf(stderr, "Error: Unable to read file content\n");
		free(content);
		exit(EXIT_FAILURE);
	}

	content[length] = '\0';
	return content;
}
