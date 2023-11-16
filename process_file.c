#include "monty.h"
#include <stdio.h>

/**
 *  readfile - function to read the content of monty file
 *  @file: the monty file
 *  @stack: the stack that we will perform the operations in
 *
 *  Return: 0 if success 1 if not
 */
int readfile(char *file, stack_t **stack)
{
	char buffer[MAX];
	int fd = 0;
	FILE *content;
	int line_number = 1;
	func ob_func;

	content = fopen(file, "r");
	if (content == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), content) != NULL)
	{
		ob_func = get_function(buffer);
		if (ob_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, buffer);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		ob_func(stack, line_number);
		line_number++;
	}
	fd = fclose(content);
	if (fd == -1)
	{
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * get_function - function to return the function that is responsible of
 * doing the specified stack operation
 * @buffer: buffer hold the operation
 *
 * Return: a function pointer to the operation or NULL
 */
func get_function(char *buffer)
{
	int i = 0;
	char *delim = " \n";
	char *token = strtok(buffer, delim);

	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{NULL, NULL}
	};
	while (ins[i].opcode != NULL && strcmp(ins[i].opcode, token) != 0)
	{
		i++;
	}
	return (ins[i].f);
}
