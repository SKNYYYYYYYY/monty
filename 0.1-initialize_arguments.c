#include "monty.h"
/**
 * initialize_arguments - Initializes the global arguments structure
 *
 * This function allocates memory for the arguments structure and its
 * instruction member, setting initial values for various fields.
 */
void initialize_arguments(void)
{


	arguments = malloc(sizeof(argument_t));
	if (arguments == NULL)
		malloc_failed();

	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->line_number = 0;
	arguments->n_tokens = 0;

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();
}
