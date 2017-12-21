#include "monty.h"
/**
 * op_nop - the opcode that does not do anything
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

void op_add(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	int sum = 0;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func(line_number, 6);
	ptr = *stack;
	while (ptr != NULL || i <= 1)
	{
		sum += ptr->n;
		ptr = ptr->next;
		i++;
	}
	printf("%d\n", sum);
}

void error_func(unsigned int line_number, int error_number)
{
	if (error_number == 1)
	{
		printf("L %d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 2)
	{
		printf("L %d: Can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 3)
	{
		printf("L %d: Can't pop, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 4)
	{
		printf("L %d: Can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 5)
	{
		printf("L %d: Can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
