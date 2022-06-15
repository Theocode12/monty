#include "monty.h"

/**
 * o_sub - subtracts the two top nodes and sets the top to the sum
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_sub(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int diff;

	temp = *top;
	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (*top)->next->n - (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = diff;
	free(temp);
}
