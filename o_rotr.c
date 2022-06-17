#include "monty.h"

/**
 * o_rotr - rotated the node at the bottom of the stack to the top
 * @top: top of the stack
 * @line_number: current line executing command
 */

void o_rotr(stack_t **top,  __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;
	
	if (*top == NULL || (*top)->next == NULL)
		return;
	temp = *top;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	(*top)->prev = temp;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*top = temp;
}
