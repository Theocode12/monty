#include "monty.h"

/**
 * o_rotl - rotates the stack to the top
 * @top: top of the stack
 * @line_number: line number with error occurence
 */

void o_rotl(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;
	unsigned int node_val = 0;
	(void) line_number;

	if (temp)
	{
		while (temp != NULL)
		{
			node_val = temp->n;
			temp->n = temp->next->n;
			temp->next->n = node_val;
			temp = temp->next;
		}
	}
}
