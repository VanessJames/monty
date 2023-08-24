#include "monty.h"
/**
  * _add - function adds top two elements of the stack
  * @head: void
  * @data: void
  */
void _add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: cant add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	pop(head, line_number);
}
