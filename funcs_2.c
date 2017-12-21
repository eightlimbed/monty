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
/**
 * op_add - adds the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func(line_number, 5);
	}
	ptr = *stack;
	if (ptr->next == NULL)
		error_func(line_number, 5);
	ptr->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
/**
 * error_func - prints various error messages and the exits the program.
 * @line_number: line number of the monty file
 * @error_number: error number given from op function
 * Return: void (EXIT_FAILURE) exit status
 */
void error_func(unsigned int line_number, int error_number)
{
	if (error_number == 1)
	{
		printf("L %d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 2)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 3)
	{
		printf("L%d: can't pop and empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 4)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (error_number == 5)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
