#include "monty.h"

/**
 * o_rotl - rotates the stack to the top
 * @top: top of the stack
 * @line_number: line number with error occurence
 */

void o_rotl(stack_t **top, unsigned int line_number)
{
	(void) line_number;

	if (*top)
		*top = (*top)->next;
}
