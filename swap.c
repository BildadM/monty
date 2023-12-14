#include <monty.h>

/**
 * swap - swaps the top two elements of the stack.
 * @stack: the stack elements
 * @line_number: the number of lines.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't swap, stack too
				short at line %u\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
