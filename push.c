#include "monty.h"
/**
* op_push - pushes an element to the stack
* @stack: pointer to the stack
* @line_number: number of line being read
* @args: array of arguments passed to opcode
*/
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *token;
	stack_t *new_node;

	token = strtok(NULL, "\t\n");

	if (token == NULL || strspn(token, "0123456789") != strlen(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
