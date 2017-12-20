#include "monty.h"
/**
 * readfile - reads each line of a file
 * @filename: path of the file (string)
 *
 * Return: void
 */

void readfile(char *filename)
{
	int number = 0, i = 0;
	char **tokens, *buffer = NULL;
	size_t size = 0;
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		/* i don't think you can close() a null file -- it was segfaulting */
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file))
	{
		tokens = parse_line(buffer);
		if (valid_op(tokens))
			printf("%s %s is valid\n", tokens[0], tokens[1]);
	}
	fclose(file);
	free(buffer);
}

int main(int argc, char *argv[])
{
	char *filename;

	filename = argv[1];
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(filename);
	return (1);
}
