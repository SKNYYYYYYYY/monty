#include "monty.h"

/**
 * push - Adds an element to the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
long value;
	if ((arguments->n_tokens <= 1) || !(is_number(arguments->token[1])))
	{
		free_arguments();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atol(arguments->token[1]);

	if ((value > INT_MAX) || (value < INT_MIN))
	{
		fprintf(stderr, "L%d: Error: integer out of range\n", line_number);
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

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack (unused).
 * @line_number: Line number in the script.
 *
 * Description: If the stack is empty, prints an error message
 * and exits the program. Otherwise, prints the value of the top
 * element of the stack.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}



/**
 * is_number - Checks if a string represents a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_number(char *str)
{
	if (*str == '-')
	{
		str++;
	}
	if (*str == '\0')
	{
		return (0);
	}
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
