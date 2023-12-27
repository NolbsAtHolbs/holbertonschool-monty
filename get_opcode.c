#include "monty.h"
#include <stdio.h>
#include <string.h>
/**
* get_opcode - ties function and opcode instructions
* @opcode: opcode to tie to function
* @stack: pointer to stack
* @line_number: number of line to read
*/
void get_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: Opcode is NULL\n");
		return;
	}
	instruction_t instructions[] =
	{
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	size_t i;

	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]) - 1; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return;
}
