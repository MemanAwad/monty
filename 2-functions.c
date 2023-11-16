#include "monty.h"

/**
 * _swap - a function that swap last two nodes in the stack
 * @stack: the stack
 * @line_number: the number of spacific line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *empty;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	empty = (*stack)->next;
	(*stack)->next = empty->next;
	if (empty->next != NULL)
		empty->next->prev = *stack;
	empty->next = *stack;
	(*stack)->prev = empty;
	empty->prev = NULL;
	*stack = empty;
}


/**
 * _add - function adds last two nodes in stack
 * @stack: tge stack
 * @line_number: the number of spacific line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
