#include "monty.h"

/**
 * check - function to check if the string contains just numbers
 * @str: the string
 *
 * Return: -1 if its not just integers 0 if it is
 */
int check(char *str)
{
	int i = 0;
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
	}
	return (0);
}

/**
 * free_stack - function to free the element of the stack
 * @stack: the stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
