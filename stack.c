#include "monty.h"

/**
 * push - push new value to the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;
	int value, is_successful;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	if (opcode_args->next == NULL || opcode_args->next->token == NULL)
	{
		push_cmd_error(stack, line_number);
	}
	is_successful = safe_atoi(opcode_args->next->token, &value);
	if (!is_successful)
	{
		push_cmd_error(stack, line_number);
	}
	new->n = value;
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	temp = *stack;
	*stack = new;
	new->next = temp;
	temp->prev = new;
}

/**
 * pall - displays the stack value
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	if (*stack == NULL)
		return;
	for (node = *stack; node; node = node->next)
		printf("%d\n", node->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * push_cmd_error - throws stack command error
 * @stk: pointer to the stack
 * @line_number: command line number
 */
void push_cmd_error(stack_t **stk, unsigned int line_number)
{
	/* TODO: free line */
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_stack(stk);
	free_opcode_args();
	exit(EXIT_FAILURE);
}
