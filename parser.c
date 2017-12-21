#include "monty.h"
/**
 * get_op_func - selects the correct function to perform from tokens
 * @tokens: array of strings
 * @line_number: line number in monty code file
 *
 * Return: pointer to the appropriate function, or NULL if not valid
 */
int arg = 0;
void (*get_op_func(char **tokens))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"pint", op_pint},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"\n", op_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (tokens == NULL)
	{
		/* blank line */
		return(ops[7].f);
	}
	while (ops[i].opcode != NULL)
	{
		if ((strcmp(ops[i].opcode, tokens[0]) == 0))
		{
			if ((strcmp(ops[i].opcode, "push") == 0) && 
				(tokens[1] == NULL || (!(valid_arg(tokens[1])))))
			{
				if (tokens[1] != NULL)
					dprintf(2,"L: unknown instruction %s %s\n", 
							tokens[0], tokens[1]);
				else
					dprintf(2,"L: unknown instruction %s\n", tokens[0]);
				free(tokens);
				exit(EXIT_FAILURE);
			}
			else if ((strcmp(ops[i].opcode, "push") == 0))
				arg = atoi(tokens[1]);
			return(ops[i].f);
		}
		i++;
	}
	dprintf(2,"L: unknown instruction %s\n", tokens[0]);
	free(tokens);
	exit(EXIT_FAILURE);
}
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
	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
	{
		printf("Error: Malloc failed");
		exit(EXIT_FAILURE);
	}
	copy = strdup(line); /* free me? */
	token = strtok(copy, " \n");
	if (token == NULL)
		return (NULL);
	i = 0;
	while (token != NULL && i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	return (tokens);
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
