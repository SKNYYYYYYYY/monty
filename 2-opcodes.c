#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 *
 * Description: If the stack has fewer than two elements,
 * prints an error message and exits the program. Otherwise,
 * swaps the values of the top two elements of the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
#include "monty.h"

/**
 * add - Adds the top two elements of the stack and removes the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 *
 * Description: If the stack has fewer than two elements,
 * prints an error message and exits the program. Otherwise,
 * adds the top two elements, removes the top element,
 * and updates the stack accordingly.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n += first->n;
	*stack = second;
	second->prev = NULL;
	free(first);

	arguments->stack_length--;
}

/**
 * sub - sub the top two elements of the stack and removes the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 *
 * Description: If the stack has fewer than two elements,
 * prints an error message and exits the program. Otherwise,
 * subtract the top two elements, removes the top element,
 * and updates the stack accordingly.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n -= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);

	arguments->stack_length--;
}

/**
 * divide - div the top two elements of the stack and removes the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 *
 * Description: If the stack has fewer than two elements,
 * prints an error message and exits the program. Otherwise,
 * divide the top two elements, removes the top element,
 * and updates the stack accordingly.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack[0] == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
	}
	first = *stack;
	second = first->next;

	second->n /= first->n;
	*stack = second;
	second->prev = NULL;
	free(first);

	arguments->stack_length--;
}

/**
 * nop - A function that does nothing.
 * @stack: Double pointer to the stack (unused).
 * @line_number: Line number in the script (unused).
 *
 * Description: This function is a placeholder in the instruction set
 * and does not perform any operation. Both parameters are ignored.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;        /* Explicitly ignore the 'stack' parameter */
	(void)line_number;  /* Explicitly ignore the 'line_number' parameter */
}
