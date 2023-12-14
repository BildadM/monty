#include "monty.h"

/**
 * pint - prints the value at the top of the stack.
 * @stack: staxk values
 * @line_number: number of lines
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "Error: can't pint an empty stack at line %u\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
