#include "monty.h"
#include <stdio.h>
/**
* free_stack - frees stack memory
* @stack: pointer to stack
*/
void free_stack(stack_t *stack)
{
	stack_t *next_node;

	while (stack != NULL)
	{
		next_node = stack->next;
		free(stack);
		stack = next_node;
	}
}
