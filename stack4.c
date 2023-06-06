#include "monty.h"

/**
 * change_list_mode - changes the list mode to give mode
 * @stk: pointer to the stack
 * @mode: mode type
 */
void change_list_mode(stack_t **stk, short mode)
{
	stack_t *node, *next;
	static short mode_opt = STACK_MODE;

	if (mode_opt == mode)
		return;
	mode_opt = mode;
	if (*stk == NULL || (*stk)->next == NULL)
		return;
	node = *stk;
	while (node)
	{
		next = node->next;
		node->next = node->prev;
		node->prev = next;
		if (next == NULL)
		{
			*stk = node;
		}
		node = next;
	}
}

/**
 * monty_stack - changes the current list to stack
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	LIST_MODE = STACK_MODE;
	change_list_mode(stack, LIST_MODE);
}

/**
 * monty_queue - changes the current list to queue
 * @stack: pointer to the stack
 * @line_number: command line number
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	LIST_MODE = QUEUE_MODE;
	change_list_mode(stack, LIST_MODE);
}
