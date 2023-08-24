#include "monty.h"

/**
 * main - Entry point of the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
void process_opcodes(FILE *file, stack_t **stack);

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	process_opcodes(file, &stack);

	fclose(file);


	return (EXIT_SUCCESS);
}
