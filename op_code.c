#include "monty.h"
/**
 * search_opcode - checks if opcode in the file is valid
 * @op_code: opcode from the file
 * @line_num: line number of the file
 * @top: top of the stack
 * @op_s: returns positive int if error occurred
 * @md: mode of operation
 */

void search_opcode(char *op_code, size_t line_num, stack_t **top, size_t *op_s, size_t md)
{
	int i = 0;
	char *args;
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
		{"rotr", o_rotr},
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
		if (md == 1)
		{
			add_to_queue(top, line_num);
			return;
		}
	}
	for (i  = 0; ops_codes[i].opcode; i++)
	{
		if (strcmp(op_code, ops_codes[i].opcode) == 0)
		{
			ops_codes[i].f(top, line_num);
			return;
		}
	}
	fprintf(stderr, "L%ld: unknown instruction %s\n", line_num, op_code);
	*op_s = 99;
}
