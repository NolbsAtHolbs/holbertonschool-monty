#include "monty.h"
/**
* swap - swaps the top two elements of the stack
* @stack: pointer to stack
* @line_number: line number read from
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *fnodes = *stack;
	int temp;

	if (fnodes == NULL || fnodes->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = fnodes->n;
	fnodes->n = fnodes->next->n;
	fnodes->next->n = temp;
}
