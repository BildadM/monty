#include "monty.h"

/**
 * pop - emoves the top element of the stack
 * @stack: stack
 * @line_number: lines to be updated
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
	fprintf(stderr, "Error: can't pop an empty stack at line %u\n", line_number);
	exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
