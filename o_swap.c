#include "monty.h"

/**
 * o_swap - swaps the two top nodes
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_swap(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;

	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*top = (*top)->next;
	temp->next = (*top)->next;
	(*top)->prev = NULL;
	(*top)->next = temp;
	temp->prev = *top;
}
