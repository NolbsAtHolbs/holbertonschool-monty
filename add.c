#include "monty.h"
/**
* add - adds the top two elements of the stack
* @stack: pointer to stack
* @line_number: number of line to read
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1p;
	stack_t *temp2pn;
	int sum;

	temp1p = *stack;
	temp2pn = (*stack)->next;

	if (temp1p == NULL || temp2pn == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = temp1p->n + temp2pn->n;

	temp1p->n = sum;
	free(temp2pn);
	temp2pn = NULL;

	(*stack)->next = temp1p->next;
	temp1p->next = NULL;
}
