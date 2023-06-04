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

/**
 * monty_pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	if (node->n < 0 || node->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);

	}
	printf("%c\n", node->n);
}

/**
 * monty_pstr - prints the whole stack as string using ascii
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	while (node && node->n != 0 && node->n > 0 && node->n <= 127)
	{
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}
