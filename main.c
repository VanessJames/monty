#include "monty.h"


vars var;


/**
 * main - Entry point of the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(argv[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (fgets(var.buff, sizeof(var.buff), var.file) != NULL)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}


	free_all();

	return (EXIT_SUCCESS);
}
