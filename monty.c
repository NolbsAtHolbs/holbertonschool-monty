#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
/**
* main - interpret monty .m files
* @argc: argument count
* @argv: argument vector
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char *argv[])
{
	char *line = NULL, *opcode;
	size_t length = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &length, file);

	while (read != -1)
	{
		opcode = strtok(line, " \t\n");

		if (opcode == NULL)
		{
			line_number += line_number;
			read = getline(&line, &length, file);
			continue;
		}
		get_op(opcode, &stack, line_number);
		read = getline(&line, &length, file);
		line_number++;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
