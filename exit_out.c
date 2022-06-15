#include "monty.h"

/**
 * exit_out - frees memory allocated before exit
 * @lineptr: getline pointer
 * @stream: opened file stream
 * @top: top of the stack
 */
void exit_out(char *lineptr, FILE *stream, stack_t *top)
{
	free(lineptr);
	fclose(stream);
	clear_stack(top);
}
