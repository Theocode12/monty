#include "monty.h"

/**
 * o_rotl - rotates thestack to the top
 * @top: top of the stack
 * @line_number: line number with error occurence
 */

void o_rotl(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;
	unsigned int node_value = 0;
	(void) line_number;

	if (temp && temp->next)
	{
		while (temp != NULL)
		{
			node_value = temp->n;
			temp->n = temp->next->n;
			temp->next->n = node_value;
			temp = temp->next;
		}
	}
}
