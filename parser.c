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

	tokens = malloc(sizeof(char *) * 3); /* only need space for 2 tokens (so far) */
	copy = strdup(line); /* free me? */
	token = strtok(copy, " ");
	i = 0;
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0 || strcmp(token, "pall") == 0)
		{
			tokens[0] = token;
			tokens[1] = token;
			tokens[2] = NULL;
			return (tokens);
		}
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
 * valid_arg - determines if a token is a valid argument
 * @tokens: array of strings (tokens)
 *
 * Return: 1 if valid argument, 0 if not
 */
int valid_arg(char **tokens)
{
	
}
