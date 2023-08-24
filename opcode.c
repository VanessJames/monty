#include "monty.h"
/**
  * push - function pushes element to the stack
  * @head: void
  * @data: function check if malloc fails
  */

void push(stack_t **head, unsigned int data)
{
	if (gs.argv[1] == NULL || !is_valid_integer(gs.argv[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", gs.line_number);
		myexit(EXIT_FAILURE, NULL)
	}

	date = atoi(gs.argv[1]);

	if (gs.mode == 1)
	{
		if (mlist_ins_end(head, data) == NULL)
			myexit(EXIT_FAILURE, "Memory allocation failure");
	}
	else
	{
		if (mylist_ins_beg(head, data) == NULL)
			myexit(EXIT_FAILURE, "Memory allocation failure");
	}
}
}
/**
  * pall -  function prints all values on stack from the top
  * @head: void
  * @data: void
  */
void pall(stack_t **head, unsigned int data)
{
	stack_t *list;
	(void)head;
	(void)data;

	list = gs.tail;
	if (gs.size == 0)
		return;

	for (; list; list = list->prev)
		printf("%d\n", list->n);
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
