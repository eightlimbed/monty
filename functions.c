#include "monty.h"
/**
 * push_op - Pushes an element onto the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	/*
	if (new_node == NULL)
		exit_func(line_number, 1);
	*/
	new_node->n = atoi(arg);
	if (*stack == NULL)
		new_node->next = NULL;
	else
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
void op_pall(stack_t **stack, unsigned int line_number, char *arg)
{
	const stack_t *ptr;
	(void) line_number;
	(void) arg;

	if (stack == NULL)
		exit(EXIT_FAILURE);
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
void op_pint(stack_t **stack, unsigned int line_number, char *arg)
{
	(void) arg;
	(void) line_number;

	/*
	if (*stack == NULL)
		error_func(line_number, 3);
	*/
	printf("%d\n", (*stack)->n);
}
/**
 * pop_op - Removes the top element of the stack.
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *ptr;
	(void) arg;
	(void) line_number;

	/*
	if (*stack == NULL)
		error_func(line_number, 4);
	*/
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
void op_swap(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *ptr;
	(void) arg;
	(void) line_number;

	ptr = (*stack)->next;
	(*stack)->prev = ptr;
	(*stack)->next = ptr->next;
	ptr->prev = NULL;
	ptr->next->prev = *stack;
	ptr->next = *stack;
	*stack = ptr;
}
