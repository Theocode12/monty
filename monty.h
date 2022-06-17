#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

extern int status;
/*#define BUFSIZE 1024*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **get_args(char *lineptr);
void search_opcode(char *op_code, size_t line_num, stack_t **top, size_t *op_s, size_t mode);
stack_t *getnode(int n);
void o_push(stack_t **top, unsigned int line_number);
void o_pall(stack_t **top, unsigned int line_number);
int check_is_digit(char *args);
void clear_stack(stack_t *top);
void exit_out(char *lineptr, FILE *stream, stack_t *top);
void o_pint(stack_t **top, unsigned int line_number);
void o_add(stack_t **top, unsigned int line_number);
void o_sub(stack_t **top, unsigned int line_number);
void o_div(stack_t **top, unsigned int line_number);
void o_pop(stack_t **top, unsigned int line_number);
void o_swap(stack_t **top, unsigned int line_number);
void o_nop(stack_t **top, unsigned int line_number);
void o_mod(stack_t **top, unsigned int line_number);
void o_mul(stack_t **top, unsigned int line_number);
void o_pchar(stack_t **top, unsigned int line_number);
void o_pstr(stack_t **top, unsigned int line_number);
void o_rotl(stack_t **top, __attribute__((unused))unsigned int line_number);
void o_rotr(stack_t **top,  __attribute__((unused))unsigned int line_number);
void add_to_queue(stack_t **top, size_t n);

#endif /*_MONTY_H*/
