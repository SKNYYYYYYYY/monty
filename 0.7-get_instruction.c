#include "monty.h"

/**
 * get_instruction - Retrieves the instruction based on the opcode
 */
void get_instruction(void)
{
	int i;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop_wrapper},
		{"swap", &swap},
		{"add", &add},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0)
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arguments->token[0]) == 0)
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 * invalid_instruction - Handles invalid instruction errors
 */
void invalid_instruction(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			arguments->line_number, arguments->token[0]);
	close_stream();
	free_tokens();
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - Frees memory allocated for tokens
 */
void free_tokens(void)
{
	int i = 0;

	if (arguments->token == NULL)
		return;

	while (arguments->token[i])
	{
		free(arguments->token[i]);
		i++;
	}
	free(arguments->token);
	arguments->token = NULL;
}

/**
 * close_stream - Closes the file stream
 */
void close_stream(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}

/**
 * pop_wrapper - Wrapper function to pop an element from the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 *
 * Description: Calls the pop function to remove the top element
 * from the stack. This function serves as a wrapper to provide
 * a default behavior of popping one element.
 */
void pop_wrapper(stack_t **stack, unsigned int line_number)
{
	pop(stack, line_number, 1);
}