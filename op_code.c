#include "monty.h"
/**
 * search_opcode - checks if opcode in the file is valid
 * @bytec_args: opcode from the file
 * @line_num: line number of the file
 * @top: top of the stack
 */

void search_opcode(char *bytec_args, size_t *line_num, stack_t **top)
{
	int i = 0;
	/*An array of strctures we will use to compare opcodes*/
	instruction_t ops_codes[] = {
		{"push", o_push},
		{"pall", o_pall},
		/*{"pop", o_pop},*/
		/*{"pint", o_pint},*/
		/*{"swap", o_add},*/
		/*{"nop", o_nop},*/
		{NULL, NULL}
	};

	for (i  = 0; ops_codes[i].opcode; i++)
	{
		/*compares the string in the array of struct with bytecodes passed*/
		if (strcmp(bytec_args, ops_codes[i].opcode) == 0)
		{
			/*if a match is found call the resulting function pointer*/
			ops_codes[i].f(top, *line_num);
			return;
		}
	}
	fprintf(stderr, "L%ld: unknown instruction %s\n", *line_num, bytec_args);
	exit(EXIT_FAILURE);
}
