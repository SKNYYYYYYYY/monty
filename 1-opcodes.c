#include "monty.h"

/**
 * push - Adds an element to the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if ((arguments->n_tokens <= 1) || !(isdigit(arguments->token[1][0])))
	{
		free_arguments();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_failed();

	new_node->n = atoi(arguments->token[1]);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	arguments->head = *stack;
	arguments->stack_length++;
}

/**
 * pall - Prints all elements in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script (not used).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;

	(void) line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
