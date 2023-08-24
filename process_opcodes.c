#include "monty.h"
/**
 * process_opcodes - Process opcodes from a file
 * and execute corresponding functions.
 * @file: Pointer to the file containing Monty byte code
 * @stack: Double pointer to the beginning of the stack
 *
 * This function reads opcodes from the given file
 * and executes the corresponding
 * functions based on the opcodes. The function
 * assumes that opcode functions like
 * push, pall, etc., are already defined and included in the project.
 */
void process_opcodes(FILE *file, stack_t **stack)
{
	char buffer[1024];
	unsigned int line_number = 1;

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		char *opcode = strtok(buffer, " \t\n");

		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(stack, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(stack, line_number);
			}
			else
			{
				fprintf(stderr, "Unknown opcode: %s\n", opcode);
			}
		}

		line_number++;
	}
}
