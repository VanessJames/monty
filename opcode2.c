#include "monty.h"

/**
 * _add - Function that adds the top two elements of the stack.
 * @head: stack head
 * @data: unsused parameter
 * @line_number: Line number of the current opcode
 */
void _add(stack_t **head, unsigned int data)
{
	(void)data;

	if (gs.size < 2)
	{
		fprintf(stderr, "L%d: cant add, stack too short\n", line_number)
		myexit(-8, NULL);
	}
	int result = gs.tail->n + gs.tail->prev->n;

	gs.tail->prev->n = result;
	pop(head, data);
}
