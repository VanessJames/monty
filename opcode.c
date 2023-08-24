#include "monty.h"
/**
  * push - function pushes element to the stack
  * @head: void
  * @data: function check if malloc fails
  */

void push(stack_t **head, unsigned int data)
{
	(void)data;

	if (gs.intarg == NULL || !is_number(gs.intarg))
	{
		fprintf(stderr, "L%d: usage integer\n", gs.line_number);
		myexit(EXIT_FAILURE);
	}
	if (gs.mode == STACK)
		mlist_ins_beg(head, atoi(gs.intarg));
	else
		mlist_ins_end(head, atoi(gs.intarg));
}
/**
  * pall -  function prints all values on stack from the top
  * @head: void
  * @data: void
  */
void pall(stack_t **head, unsigned int data)
{
	stack_t *list = *head;

	(void)data;

	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}
/**
* pint- prints value on the top of the stack
* @head: void
* @data: void
*/
void pint(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;

	if (gs.size == 0)
		myexit(-6, "pint");

	printf("%d\n", gs.tail->n);
}
/**
  * pop - function removes the top element of the stack
  * @head: void
  * @data: void
  */
void pop(stack_t **head, unsigned int data)
{
	(void)head;
	(void)data;

	if (gs.size == 0)
		myexit(-7, NULL);
	mlist_remove(gs.tail);
}
/**
* swap - function swaps top two elements of stack
* @head: void
* @data: function store integer from node
*/
void swap(stack_t **head, unsigned int data)
{
	(void)head;
	if (gs.size <= 2)
		myexit(-8, "swap");

	data = gs.tail->n;
	gs.tail->n = gs.tail->prev->n;
	gs.tail->prev->n = data;
}
