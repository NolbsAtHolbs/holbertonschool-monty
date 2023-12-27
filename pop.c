#include "monty.h"
/**
* pop - removes the top element of the stack
* @stack: pointer to stack
* @line_number: number of line being read
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *old_node = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	old_node = *stack;
	*stack = (*stack)->next;
	free(old_node);
}
