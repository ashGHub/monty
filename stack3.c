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

/**
 * monty_rotl - the top element becomes the last
 *              and the second element becomes the first
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *first_node, *second_node;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first_node = *stack;
	second_node = (*stack)->next;
	for (node = *stack; node->next; node = node->next)
		;
	second_node->prev = NULL;
	*stack = second_node;
	node->next = first_node;
	first_node->prev = node;
	first_node->next = NULL;
}

/**
 * monty_rotr - the last element becomes the top element
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *first_node;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first_node = *stack;
	for (node = *stack; node->next; node = node->next)
		;
	node->prev->next = NULL;
	node->next = first_node;
	node->prev = NULL;
	first_node->prev = node;
	*stack = node;
}
