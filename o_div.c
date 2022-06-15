#include "monty.h"

/**
 * o_div - divides the two top nodes and sets the top to the sum
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_div(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int div;

	temp = *top;
	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*top)->next->n / (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = div;
	free(temp);
}
