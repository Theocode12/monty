#include "monty.h"

/**
 * o_rotl - rotates the top element of the stack to the bottom
 * @top: top of the stack
 * @line_number: line number with error occurence
 */

void o_rotl(stack_t **top, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
		return;
	temp = *top;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	(*top)->prev = temp;
	*top = (*top)->next;
	temp->next->next = NULL;
}
