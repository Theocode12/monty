#include "monty.h"

/**
 * o_pint - peeks the integer on the stack
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);

}
