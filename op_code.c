#include "monty.h"
/**
 * search_opcode - checks if opcode in the file is valid
 * @op_code: opcode from the file
 * @line_num: line number of the file
 * @top: top of the stack
 * @op_s: returns positive int if error occurred
 */

void search_opcode(char *op_code, size_t line_num, stack_t **top, size_t *op_s)
{
	int i = 0;
	char *args;
	/*An array of strctures we will use to compare opcodes*/
	instruction_t ops_codes[] = {
		{"push", o_push},
		{"pall", o_pall},
		{"pop", o_pop},
		{"pint", o_pint},
		{"add", o_add},
		{"sub", o_sub},
		{"div", o_div},
		{"swap", o_swap},
		{"nop", o_nop},
		{"mul", o_mul},
		{"mod", o_mod},
		{"pchar", o_pchar},
		{"pstr", o_pstr},
		{"rotl", o_rotl},
		{NULL, NULL}
	};

	if (strcmp(op_code, "push") == 0)
	{
		args = strtok(NULL, " \n\r\t");
		if (args == NULL  || check_is_digit(args))
		{
			fprintf(stderr, "L%ld: usage: push integer\n", line_num);
			*op_s = 100;
			return;
		}
		line_num = atoi(args);
	}
	for (i  = 0; ops_codes[i].opcode; i++)
	{
		/*compares the string in the array of struct with bytecodes passed*/
		if (strcmp(op_code, ops_codes[i].opcode) == 0)
		{
			/*if a match is found call the resulting function pointer*/
			ops_codes[i].f(top, line_num);
			return;
		}
	}
	fprintf(stderr, "L%ld: unknown instruction %s\n", line_num, op_code);
	*op_s = 99;
}
