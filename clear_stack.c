#include "monty.h"

/**
 * clear_stack - clears all nodes in the stack
 * @top: top of the stack
 * Description: stack is being cleared from left to right
 */
void clear_stack(stack_t *top)
{
	stack_t *temp = top;

	while (top)
	{
		top = top->next;
		free(temp);
		temp = top;
	}
}
