#include "monty.h"
/**
 * push_op - Pushes an element onto the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit_func(line_number, 1);
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}
/**
 * pall_op - Prints all elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	const stack_t *ptr;

	if (stack == NULL)
		exit;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * pint_op - Prints the value at the top of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_func(line_number, 3);
	printf("%d\n", (*stack)->next->n);
}
/**
 * pop_op - Removes the top element of the stack.
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t ptr;

	if (*stack == NULL)
		error_func(line_number, 4);
	ptr = (*stack)->next;
	(*stack) = ptr;
	free(ptr->prev);
	ptr->prev = NULL;
}
/**
 * swap_op - swaps top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = (*stack)->next;
	ptr->next->prev = (*stack);
	(*stack)->prev = ptr;
	(*stack)->next = ptr->next;
	ptr->prev = NULL;
	(*stack) = ptr;
}
