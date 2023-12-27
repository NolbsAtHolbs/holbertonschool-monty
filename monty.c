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
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		parse_instructions(&stack, line, line_number);
		line_number++;
	}
	free(line);
	free_memory(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
