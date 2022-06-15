#include "monty.h"

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