#include "monty.h"
/**
 * parse_line - parses a line into tokens. tokens separated by spaces. only
 * first two tokens will be returned.
 * @line: buffer from getline in readfile() in monty.c.
 *
 * Return: null-terminated array of two tokens, or NU
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
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0 || strcmp(token, "pall") == 0)
		{
			tokens[0] = token;
			if (strcmp(token, "pall") == 0)
			/* pall's second token will be NULL because it takes no args */
			{
				tokens[1] = NULL;
				return (tokens);
			}
			token = strtok(NULL, " \n");
			/* argument */
			tokens[1] = token;
			tokens[2] = NULL;
			return (tokens);
		}
		else
		{
			/* if not "push" or "pall", the whole line becomes token[0] */
			tokens[0] = line;
			tokens[1] = NULL;
			return (tokens);
		}
		free(copy);
		return (NULL);
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
	printf("tokens: \n0: [%s]\n1: [%s]\n", tokens[0], tokens[1]);
	if (strcmp(tokens[0], "push") == 0)
	{
		/* if "push" we need to check token[1] for valid arg */
		if (tokens[1] == NULL)
			return (0);
		else
		{
			if (valid_arg(tokens[1]))
				return (1);
		}
	}
	else if (strcmp(tokens[0], "pall") == 0)
	{
		if (tokens[1] == NULL)
			return (1);
		else
			return (0);
	}
	return (0);
}
/**
 * valid_arg - determines if a token is a valid argument
 * @token: argument token from valid_op.
 *
 * Return: 1 if valid argument, 0 if not
 */
int valid_arg(char *token)
{
	unsigned int i;
	
	/* if token is NULL its an op with no argument, so its valid */
	if (token == NULL)
		return (1);
	i = 0;
	while (token[i] != '\0')
	{
		if (token[0] == '-')
		{
			if ((!(token[1] >= '0' && token[1] <= '9')) || token[1] == '\0')
				return (0);
			else
			{
				i = 1;
				while (token[i] >= '0' && token[i] <= '9')
				{
					i++;
					if (token[i] == '\0')
						return (1);
				}
				return (0);
			}
		}
		else
		{
			i = 0;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}
