#include "monty.h"

int main(void)
{
	int i;
	ssize_t bytes_read;
	long int file_size;
	char *dir;
	char *buffer;
	char *fullname;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char **tokens;

	buffer = malloc(1024);
	dir = getcwd(buffer, 1024);
	fullname = strcat(dir, "/001.m");
	fp = fopen(fullname, "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", fullname);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = getline(&line, &len, fp)) != -1)
	{
		tokens = parse_line(line);
		i = 0;
		while (tokens[i] != NULL)
		{
			printf("token %d: %s\n", i, tokens[i]);
			i++;
		}
	}
	free(line);
	free(buffer);
	fclose(fp);
	return (0);
}
