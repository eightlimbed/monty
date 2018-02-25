#include "monty.h"
/**
 * op_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: head node to the stack
 * @line_number: line number of the monty file
 * Return: void (EXIT_FAILURE) exit status
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if (*stack == NULL || stack == NULL)
		error_func(line_number, 12);
	x = (*stack)->n;
	if (x >= 1 && x <= 127)
	{
		putchar(x);
		putchar('\n');
	}
	else
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: head node to the stack.
 * @line_number: line number of the monty file
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int x = 0;

	(void)line_number;
	if (*stack == NULL || stack == NULL)
		putchar('\n');
	else
	{
		ptr = *stack;
		while (ptr != NULL)
		{
			x = ptr->n;
			if (x >= 1 && x <= 127)
				putchar(x);
			else
				break;
			ptr = ptr->next;
		}
		putchar('\n');
	}
}
