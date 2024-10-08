#include "monty.h"

argument_t *arguments = NULL;

/**
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	size_t n = 0, len;
	int read;
	stack_t *stack = NULL;

	check_args(argc);
	initialize_arguments();
	get_stream(argv[1]);

	while ((read = getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		len = strlen(arguments->line);
		if (len > 0 && arguments->line[len - 1] == '\n')
			arguments->line[len - 1] = '\0';

		arguments->line_number++;
		tokenize_line();
		run_command(&stack);
		free_tokens();
	}

	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	free_arguments();
	return (0);
}
