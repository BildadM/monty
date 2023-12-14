#include "monty.h"

stack_t *stack = NULL;

/**
 * main - start of program
 * @argc: argument
 * @argv: number of arguments
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
FILE *file = fopen(argv[1], "r");
char instruction[100];
unsigned int line_number = 1;
int value;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (EXIT_FAILURE);
}
if (file == NULL)
{
fprintf(stderr, "Error: Failed to open file '%s'\n", argv[1]);
return (EXIT_FAILURE);
}
while (fscanf(file, "%s", instruction) != EOF)
{
if (strcmp(instruction, "push") == 0)
{
char arg[100];

if (fscanf(file, "%s", arg) == EOF)
{
fprintf(stderr, "Error: Not enough arguments for push at line %u\n", line_number);
fclose(file);
return (EXIT_FAILURE);
}
if (!isInteger(arg))
{
fprintf(stderr, "Error: Invalid argument for push at line %u\n", line_number);
fprintf(stderr, "Usage: push integer\n");
fclose(file);
return (EXIT_FAILURE);
}
value = atoi(arg);
push(&stack, value);
}
else if (strcmp(instruction, "pop") == 0)
pop(&stack, line_number);
else if (strcmp(instruction, "pint") == 0)
pint(&stack, line_number);
else if (strcmp(instruction, "pall") == 0)
pall(&stack, line_number);
else if (strcmp(instruction, "swap") == 0)
swap(&stack, line_number);
else if (strcmp(instruction, "add") == 0)
add(&stack, line_number);
else if (strcmp(instruction, "nop") == 0)
line_number++;
}
fclose(file);
return (0);
}
