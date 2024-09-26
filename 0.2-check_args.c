#include "monty.h"

/**
 * check_args - Validates the number of command-line arguments
 * @argc: The number of command-line arguments
 *
 * Return: 0 if the number of arguments is correct, otherwise exits the program
 */
int check_args(int argc)
{
	if (argc == 2)
		return (0);

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
