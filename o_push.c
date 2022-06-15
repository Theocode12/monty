#include "monty.h"

/**
 * o_push - pushes a node onto the stack
 * @top: top of the stack
 * @line_number: currect line number at which command is
 */

void o_push(stack_t **top, unsigned int line_number)
{
	stack_t *nw_node = NULL;

	nw_node = getnode(line_number);
	if (*top == NULL)
	{
		*top = nw_node;
		return;
	}
	(*top)->prev = nw_node;
	nw_node->next = *top;
	*top = nw_node;
}

/**
 * check_is_digit - check if a string is okay to be changed to an int
 * @args: string to be checked
 * Return: if successful return 1 else 0
 */

int check_is_digit(char *args)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		if ((args[0] == '-'))
			continue;
		if (isdigit(args[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * getnode - creates a node to be added on stack
 * @n: integer data for node
 * Return: address of created node
 */

stack_t *getnode(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
