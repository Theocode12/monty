#include "monty.h"

/**
 * o_pop - removes the node at the top of the stack
 * @top: top of the stack
 * @line_number: current line executing command
 */

void o_pop(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	free(*top);
	*top = temp;
}
