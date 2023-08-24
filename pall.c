#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (!current)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - Insert a new value in the list
 * @stack: Double linked list
 * @line_number: The File line execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	current = malloc(sizeof(stack_t));
	if (!current)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	current->n = atoi(num);
	if (var.MODE == 0 || !*stack)
	{
		current->next = *stack;
		current->prev = NULL;
		if (*stack)
			(*stack)->prev = current;
		*stack = current;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = current;
		current->prev = tm;
		current->next = NULL;
	}
}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - Delete top of list
* @stack: Double linked list
* @line_number: File line execution
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = current->next;
	if (current->next)
		current->next->prev = NULL;
	free(current);
}
