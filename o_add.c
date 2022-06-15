#include "monty.h"
/**
 * o_add - adds the two top nodes and sets the top to the sum
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_add(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	temp = *top;
	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*top)->n + (*top)->next->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = sum;
	free(temp);
}
