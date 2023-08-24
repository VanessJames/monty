#include "monty.h"

/**
 * _add - Function that adds the top two elements of the stack.
 * @head: Double pointer to the head of the stack
 * @line_number: Line number of the current opcode
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head)->next->n += temp->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
