#include "monty.h"

int main(int argc, char *argv[])
{
	unsigned int i, line_count;
	ssize_t bytes_read;
	char *dir, *buffer, *fullname;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char **tokens;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty <file>\n");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(1024);
	dir = getcwd(buffer, 1024);
	fullname = strcat(dir, "/");
	fullname = strcat(fullname, argv[1]);
	fp = fopen(fullname, "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", fullname);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = getline(&line, &len, fp)) != -1)
	{
		line_count++;
		tokens = parse_line(line);
		printf("tokens[0]: %s\ttokens[1]: %s\n", tokens[0], tokens[1]);
		if (strcmp(tokens[0], line) == 0)
		{
			dprintf(2, "L%d: unknown instruction %s", line_count, line);
			free(line);
			exit(EXIT_FAILURE);
		}
		/*
		i = 0;
		while (tokens[i] != NULL)
		{
			printf("token %d: %s\n", i, tokens[i]);
			if (valid_op(tokens))
				printf("valid\n");
			i++;
		}
		*/
	}
	free(line);
	free(buffer);
	fclose(fp);
	return (0);
}
