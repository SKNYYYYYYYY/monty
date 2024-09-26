#include "main.h"

/**
 * run_command - Executes a command on the stack.
 * @stack: Double pointer to the stack.
 */
void run_command(stack_t **stack)
{
	if (arguments->n_tokens == 0)
	{
		return;
	}

	get_instruction();

	if (arguments->instruction->f != NULL)
	{
		arguments->instruction->f(stack, arguments->line_number);
	}
}
