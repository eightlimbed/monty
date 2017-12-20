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
	char *buffer = NULL;
	size_t size = 0;
	FILE *file;
	char **tokens;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fclose (file);
		printf("Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file))
	{
		tokens = parse_line(buffer);
		printf("%d: %s\t%s\n", number++, tokens[0], tokens[1]);
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
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	readfile(filename);
	return (1);
}
