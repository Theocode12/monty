#include "monty.h"

/**
 * o_pchar - prints the char atthe top of the stack
 * followed by a new line
 * @top: the top of the stack
 * @line_number: the line_number
 */

void o_pchar(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n >= 0 && (*top)->n <= 127)
	{
		printf("%c\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
