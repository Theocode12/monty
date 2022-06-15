#include "monty.h"

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
	return;
}