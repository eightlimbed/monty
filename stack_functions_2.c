#include "monty.h"

void op_pchar(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if (*stack == NULL || stack == NULL)
		error_func(line_number, 12);
	x = (*stack)->n;
	if (x >= 1 && x <= 127)
		putchar(x);
	else
	{
		printf("L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
}
