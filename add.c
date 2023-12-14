#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: stack
 * @line_number: number of lines
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "Error: can't add, stack too short at line %u\n", line_number);
	exit(EXIT_FAILURE);
}

(*stack)->next->n += (*stack)->n;
pop(stack, line_number);
}
