#include "monty.h"
/**
 * readfile - reads each line of a file
 * @filename: path of the file (string)
 *
 * Return: void
 */

stack_t *stack = NULL;
void readfile(char *filename)
{
	int number = 0;
	char **tokens, *buffer = NULL;
	size_t size = 0;
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file))
	{
		number++;
		tokens = parse_line(buffer);
		if (valid_op(tokens))
		{
			/* do stuff */
			get_op_func(tokens)(&stack, number, tokens[1]);
		}
		if (tokens == NULL)
		{
			/* blank line */
			free(tokens);
			free(buffer);
			continue;
		}
		if (!(valid_op(tokens)))
		{
			dprintf(2,"L%d: unknown instruction %s\n", number, tokens[0]);
			free(tokens);
			free(buffer);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free(tokens);
	free(buffer);
	fclose(file);
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
