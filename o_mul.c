#include "monty.h"

/**
 * o_mul - mul the two top nodes and sets the top to the product
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_mul(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int mul;

	temp = *top;
	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*top)->next->n * (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = mul;
	free(temp);
}
