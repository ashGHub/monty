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
