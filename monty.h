#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;
extern stack_t *stack;
char **parse_line(char *line);
int valid_op(char **tokens);
int valid_arg(char *tokens);
void (*get_op_func(char **tokens))(stack_t **stack, unsigned int line_number, char *arg);
void op_push(stack_t **stack, unsigned int line_number, char *arg);
void op_pall(stack_t **stack, unsigned int line_number, char *arg);
void op_pop(stack_t **stack, unsigned int line_number, char *arg);
void op_pint(stack_t **stack, unsigned int line_number, char *arg);
void op_swap(stack_t **stack, unsigned int line_number, char *arg);
#endif
