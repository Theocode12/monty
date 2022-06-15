#include "monty.h"

void search_opcode(char *bytec_args, size_t *line_num, stack_t **top)
{
	int i = 0;
	instruction_t ops_codes[] = {
		{"push", o_push},
		{"pall", o_pall},
		/*{"pop", o_pop},
		{"pint", o_pint},
		{"swap", o_add},
		{"nop", o_nop},*/
		{NULL, NULL}
	};

	for(i  = 0; ops_codes[i].opcode; i++)
	{
		if (strcmp(bytec_args, ops_codes[i].opcode) == 0)
		{
			ops_codes[i].f(top, *line_num);
			return;
		}
	}
	
	fprintf(stderr, "L%ld: unknown instruction %s\n", *line_num, bytec_args);
	exit(EXIT_FAILURE);
}