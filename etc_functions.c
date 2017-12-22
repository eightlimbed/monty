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
 * error_func - prints various error messages and the exits the program.
 * @line_number: line number of the monty file
 * @error_number: error number given from op function
 * Return: void (EXIT_FAILURE) exit status
 */
void error_func(unsigned int line_number, int error_number)
{
	if (error_number == 1)
		printf("L%d: usage: push integer", line_number);
	else if (error_number == 2)
		printf("L%d: can't pint, stack empty\n", line_number);
	else if (error_number == 3)
		printf("L%d: can't pop an empty stack\n", line_number);
	else if (error_number == 4)
		printf("L%d: can't swap, stack too short\n", line_number);
	else if (error_number == 5)
		printf("L%d: can't add, stack too short\n", line_number);
	else if (error_number == 6)
		printf("L%d: can't sub, stack too short\n", line_number);
	else if (error_number == 7)
		printf("L%d: can't div, stack too short\n", line_number);
	else if (error_number == 8)
		printf("L%d: division by zero\n", line_number);
	else if (error_number == 9)
		printf("L%d: can't mul, stack too short\n", line_number);
	else if (error_number == 10)
		printf("L%d: can't mod, stack too short\n", line_number);
	else if (error_number == 11)
		printf("L%d: division by zero\n", line_number);
	else if (error_number == 12)
		printf("L%d: can't pchar, value out of range", line_number);
	exit(EXIT_FAILURE);
}
/**
 * free_list - frees a doubly-linked list
 * @stack: pointer to head node
 * Return: void
 */
void free_list(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp == NULL)
			return;
		temp->prev = NULL;
		*stack = temp;
	}
	free(*stack);
}
