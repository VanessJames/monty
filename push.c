#include "monty.h"
#include <ctype.h>

/**
 * is_number - Checks if a string is a valid number.
 * @str: String to be checked
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new_node;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
