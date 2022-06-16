#include "monty.h"
/**
 * o_mod - mod the two top nodes and sets the top to the remainder
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_mod(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int mod;

	temp = *top;
	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*top)->next->n % (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = mod;
	free(temp);
}
