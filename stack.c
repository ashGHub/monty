#include "monty.h"

/**
 * monty_push - push new value to the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_push(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	is_successful = safe_atoi(opcode_args->next->token, &value);
	if (!is_successful)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
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
 * monty_pall - displays the stack value
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	if (*stack == NULL)
		return;
	for (node = *stack; node; node = node->next)
		printf("%d\n", node->n);
}

/**
 * monty_pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * monty_pop - pop the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(node);
}

/**
 * monty_swap - swap the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_node, *second_node, *third_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *stack;
	second_node = (*stack)->next;
	third_node = (*stack)->next->next;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->next = third_node;
	first_node->prev = second_node;
	if (third_node != NULL)
	{
		third_node->prev = first_node;
	}
	*stack = second_node;
}
