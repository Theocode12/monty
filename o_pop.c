#include "monty.h"

/**
 * o_pop - removes the node at the top of the stack
 * @top: top of the stack
 * @line_number: current line executing command
 */

void o_pop(stack_t **top, unsigned int line_number)
{
	stack_t *prevNode;
	stack_t *temp = *top;
	
	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = top->next;
		prevNode->next = NULL;
		free(temp)
	}
