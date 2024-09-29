#include "monty.h"
/**
 * mul - multiply the top two elements of the stack and removes the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 *
 * Description: If the stack has fewer than two elements,
 * prints an error message and exits the program. Otherwise,
 * multiply the top two elements, removes the top element,
 * and updates the stack accordingly.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n *= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);

	arguments->stack_length--;
}
