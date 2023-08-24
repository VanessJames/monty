#include "monty.h"
/**
  * _add - function adds top two elements of the stack
  * @head: void
  * @data: void
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
