#include "monty.h"

/**
 * _add - Function that adds the top two elements of the stack.
 * @head: Double pointer to the head of the stack
 * @line_number: Line number of the current opcode
 */
void _add(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "add");
	data = gs.tail->n;
	mlist_remove(gs.tail);
	data += gs.tail->n;
	gs.tail->n = data;
}
