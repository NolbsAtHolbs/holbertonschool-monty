#include "monty.h"
/**
* pall - prints all the values on the stack, starting from the top of the stack
* @stack: pointer to stack
* @line_number: number of line being read
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
