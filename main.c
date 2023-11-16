#include "monty.h"

/**
 * main - to run the code of the stack it will create a stack
 * object and check if we can open the file of stack operations
 * then it will call a function to process the file
 * @ac: the number of the argument to the program
 * @argv: the array og arguments
 *
 * Return: 0 if success EXIT_FAILURE if not
 */
int main(int ac, char *argv[])
{
	stack_t *stack = NULL;

	if (ac != 2)
	{

		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	readfile(argv[1], &stack);
	free_stack(&stack);
	return (0);
}
