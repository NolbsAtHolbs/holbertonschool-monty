#include "monty.h"
/**
* pint - prints the value at the top of the stack, followed by a new line.
* @stack: pointer to the stack
* @line_number: number of line being read
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;

	if (top == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
