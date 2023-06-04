#include "monty.h"

/**
 * monty_mod - get the remainder/mode of the second top element
 *             with the first one
 * @stack: pointer to the stack
 * @line_number: command line number
 *
 * Description: set the remainder to the second element
 *              and removes the first element
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack)->next->n = ((*stack)->next->n % node->n);
	monty_pop(stack, line_number);
}
