#include "monty.h"

void o_push(stack_t **top, __attribute__((unused))unsigned int line_number)
{
	char *args = strtok(NULL, " \n\r\t");
	int n;
	stack_t *nw_node = NULL;

	if (args == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if ( check_is_digit(args))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(args);
	nw_node = getnode(n);
	if (*top == NULL)
	{
		*top = nw_node;
		return;
	}
	(*top)->prev = nw_node;
	nw_node->next = *top;
	*top = nw_node;
	return;
}

int check_is_digit(char *args)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		if ((args[i] = '-') && (i == 0))
			continue;
		if (isdigit(args[i]) == 0)
			return (1);
	}
	return (0);
}