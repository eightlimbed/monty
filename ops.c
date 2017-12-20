#include "monty.h"
/**
 * op_push - pushes an element on the stack
 * @stack: address of head node
 * @line_number: monty file line number
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number, char *arg)
{
	int value;

	value = atoi(arg);
	printf("pushing %d...\n", value);
}
/**
 * op_pall - prints all elements of the stack
 * @stack: address of head node
 * @line_number: monty file line number
 *
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number, char *arg)
{
	printf("printing elements...\n");
}
