#include "monty.h"

/**
 * swap - Delete top of list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int current;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = current;
}

/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
