#include "monty.h"

/**
 * o_pstr - prints the string starting at the top of the stack
 * followed by a new line
 * @top: top of the stack
 * @line_number: line number of stack
 */

void o_pstr(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		printf("\n");
	}

	if (0 <= (*top)->n <= 127)
	{
		while ((*top)->next == NULL || (*top)->n == 48 || (*top)->n > 127)
		{
			break;
		}
		printf("%c\n", (*top)->n);
	}
}
