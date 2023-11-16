#include "monty.h"

/**
 * _sub - a function that substract last node in the stack from node above
 * @stack: the stack
 * @line_number: the number of spacific line
 *
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;

}

