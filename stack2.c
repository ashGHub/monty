#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void swap(stack_t **stack, unsigned int line_number)
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

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 *
 * Description: set the sum to the second element
 *              and removes the first element
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack)->next->n = (node->n + (*stack)->next->n);
	pop(stack, line_number);
}

/**
 * nop - does not do anything
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* does not do anything */
}

/**
 * sub - substract the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: command line number
 *
 * Description: set the difference to the second element
 *              and removes the first element
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack)->next->n = ((*stack)->next->n - node->n);
	pop(stack, line_number);
}
