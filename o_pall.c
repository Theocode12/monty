#include "monty.h"

void o_pall(stack_t **top, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *top;
	char *args = strtok(NULL, " \t\n\r");
	
	if (temp == NULL)
		return;
	if (args != NULL)
	{
		fprintf(stderr,"L%d: unknown instruction %s\n", line_number, args);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return;
}