#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"


int main(int argc, char **argv)
{
	char *lineptr = NULL, *bytec_args = NULL;
	size_t n = 0, line_num = 0;
	FILE *stream = NULL;
	stack_t *top = NULL;

	if (argc <= 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
		bytec_args = strtok(lineptr, " \r\n\t");
		search_opcode(bytec_args, &line_num, &top);
	}
	free(lineptr);
	fclose(stream);
	clear_stack(top);
	exit (EXIT_SUCCESS);
}



stack_t *getnode(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return node;
}
















/*char **get_args(char *lineptr)
{
	char **holdargs;
	int i = 0;

	holdargs = malloc(sizeof(char *) * 3);
	if (holdargs == NULL)
	{
		fprintf(stderr,"Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	holdargs[i] = strtok(lineptr, " \n\r\t");
	while (holdargs[i] != NULL && *(holdargs[i]) != '#')
		holdargs[++i] = strtok(NULL, " \n\t\r");
	holdargs[i] = NULL;
	return (holdargs);

}*/