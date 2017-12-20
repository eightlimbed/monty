#include "monty.h"
/**
 * parse_line - parses a line into tokens
 * @line: string
 *
 * Return: array of strings (tokens)
 */

void readfile(char *filename)
{
	int number = 0, i = 0;
	char *buffer = NULL;
	size_t size = 0;
	FILE *file;
	char **lines;
	lines = malloc(sizeof(char *) * 10);
	if (lines == NULL)
		return;
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fclose (file);
		printf("Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file))
	{
		lines[i] = buffer;
		printf("Line # %d - %s\n", number++, lines[i]);
		i++;
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
