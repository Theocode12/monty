#include "monty.h"

/**
 * o_pall - prints all data in the stack
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_pall(stack_t **top, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *top;

	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
