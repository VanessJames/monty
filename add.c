#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @l_numb: line_number
 * Return: no return statement
*/

void _add(stack_t **head, unsigned int l_numb)
{
	stack_t *hh;
	int lenght = 0, temp;

	hh = *head;

	while (hh)
	{
		hh = hh->next;
		lenght++;
	}

	if (lenght < 2)
	{
		printf(stderr, "L%d: can't add, stack too short\n", counter);
	clean_up_resources(head);
	exit(EXIT_FAILURE);
	}

	hh = *head;

	temp = hh->nn + hh->next->nn;
	hh->next->nn = temp;
	*head = hh->next;
	free(h);
}
