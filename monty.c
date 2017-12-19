#include "monty.h"

int main(void)
{
	char **tokens;
	unsigned int i;
	int x;
	
	tokens = parse_line("  ragged  ");
	if (tokens == NULL)
	{
		printf("null tokens\n");
		return (1);
	}
	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("token %d: %s\n", i, tokens[i]);
	}
	x = valid_op(tokens);
	if (x)
		printf("valid\n");
	free(tokens);
	return (0);
}
