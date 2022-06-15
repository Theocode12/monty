#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/**
 * main - Entry point for monty bytecode
 * @argc: arguement count
 * @argv: arguement vector
 * Return: exit success on successful execution
 */

int main(int argc, char **argv)
{
	char *lineptr = NULL, *bytec_args = NULL;
	size_t n = 0, line_num = 0;
	FILE *stream = NULL;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file  %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, stream) != -1)
	{
		line_num++;
		/*get the first args in a line e.g push*/
		bytec_args = strtok(lineptr, " \r\n\t");
		/*from here below will be modified but search_opcode will always run*/
		if (strcmp(bytec_args, "NULL") == 0)
			bytec_args = NULL;
		if (bytec_args && bytec_args[0] != '#')
			search_opcode(bytec_args, &line_num, &top);
	}
	free(lineptr);
	fclose(stream);
	clear_stack(top);
	exit(EXIT_SUCCESS);
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
