#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 *
 * Description: set the sum to the second element
 *              and removes the first element
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack)->next->n = (node->n + (*stack)->next->n);
	monty_pop(stack, line_number);
}

/**
 * monty_nop - does not do anything
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* does not do anything */
}

/**
 * monty_sub - substract the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 *
 * Description: set the difference to the second element
 *              and removes the first element
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack)->next->n = ((*stack)->next->n - node->n);
	monty_pop(stack, line_number);
}

/**
 * monty_div - divides the second top element with the first one
 * @stack: pointer to the stack
 * @line_number: command line number
 *
 * Description: set the quotient to the second element
 *              and removes the first element
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack)->next->n = ((*stack)->next->n / node->n);
	monty_pop(stack, line_number);
}
