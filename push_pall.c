#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: the stack to be implemented.
 * @value: integer to be passed
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack.
 * @stack: the elements
 * @line_number: number of lines
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * isInteger - determines whether a value is an integer
 * @str: value to be determined.
 * Return: true value
 */
bool isInteger(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (*str == '\0')
	{
		return (false);
	}
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (false);
		}
		str++;
	}
	return (true);
}
