#include "monty.h"
/**
 * parse_line - parses a line into tokens
 * @line: string
 *
 * Return: array of strings (tokens)
 */
char **parse_line(char *line)
{
	char *token, *copy, **tokens;
	unsigned int i;

	if (line == NULL)
	{
		dprintf(2, "Error: Invalid Line\n");
		exit(EXIT_FAILURE);
	}
	tokens = malloc(sizeof(char *) * 3);
	copy = strdup(line); /* free me? */
	token = strtok(copy, " \n");
	i = 0;
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0 || strcmp(token, "pall") == 0)
		{
			tokens[0] = token;
			if (strcmp(token, "pall") == 0)
			{
				tokens[1] = NULL;
				return (tokens);
			}
			token = strtok(NULL, " \n");
			tokens[1] = token;
			tokens[2] = NULL;
			return (tokens);
		}
		free(copy);
		return (NULL);
		i++;
	}
}
/**
 * valid_op - determines if a token is a valid operation
 * @tokens: array of strings (tokens)
 *
 * Return: 1 if valid, 0 if not
 */
int valid_op(char **tokens)
{
	unsigned int i;
	char *ops[3];

	ops[0] = "push";
	ops[1] = "pall";
	ops[2] = NULL;

	i = 0;
	while (ops[i] != NULL)
	{
		if (strcmp(tokens[0], ops[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
/**
 * valid_arg - determines if a token is a valid argument (pos or neg integer)
 * @tokens: array of strings (tokens)
 *
 * Return: 1 if valid argument, 0 if not
 */
int valid_arg(char **tokens)
{
	unsigned int i;
	
	printf("valid_arg looking at %s\n", tokens[1]);
	i = 0;
	while (tokens[1][i] != '\0')
	{
		if (tokens[1][0] != '-' &&
		   (!(tokens[1][i] >= '0' && tokens[1][i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}
