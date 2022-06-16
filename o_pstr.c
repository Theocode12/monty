#include "monty.h"

/**
 * o_pstr - prints the string starting at the top of the stack
 * followed by a new line
 * @top: top of the stack
 * @line_number: line number of stack
 */

void o_pstr(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;
	(void) line_number;

	while (temp != NULL)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;

		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
