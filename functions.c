#include "monty.h"

/**
 * _push - a function to push a nide to stack
 * @stack: the stack
 * @line_number: the number of spacific line
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *empty;
	stack_t *new_node;
	char *num;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	num = strtok(NULL, " \n\t\r");
	if (check(num) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(num);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	empty = *stack;
	*stack = new_node;
	(*stack)->next = empty;
	empty->prev = *stack;
}

/**
 * _pall - a function to print all stack's nodes
 * @stack: the satck
 * @line_number: the number of spacific line
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *empty;

	(void)line_number;
	if (*stack == NULL)
	{
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		empty = *stack;
		while (empty != NULL)
		{
			printf("%d\n", empty->n);
			empty = empty->next;
		}
	}
}


/**
 * _pint - a function that print the last node in stack
 * @stack: the stack
 * @line_number: the number of spacific line
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * _pop - a function delete the last node in stack
 * @stack: the stack
 * @line_number: the number of spacific line
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *empty;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	empty = *stack;
	*stack = empty->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(empty);
}


/**
 * _nop - a function do nothing
 * @stack: the stack
 * @line_number: the number of spacific line
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
