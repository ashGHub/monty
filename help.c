#include "monty.h"

/**
 * invalid_opcode - prints invalid opcode inststuction error
 * @code: invalid opcode
 * @n: invalid opcode line number
 */
void invalid_opcode(char *code, int n)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", n, code);
}

/**
 * malloc_error - prints malloc error
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
}

/**
 * free_opcode_args - frees the global variable opcode
 *                    and its args using linked list
 */
void free_opcode_args(void)
{
	opcode_token_t *temp = NULL, *node = opcode_args;

	if (opcode_args == NULL)
	{
		return;
	}
	while (node)
	{
		temp = node->next;
		free(node->token);
		free(node);
		node = temp;
	}
	opcode_args = NULL;
}

/**
 * set_opcode_args - sets the global variable opcode
 *                   with its args using linked list
 *                   the head being the opcode and
 *                   the rest of the nodes as argument
 * @line: line to parse
 */
void set_opcode_args(char *line)
{
	short result = 0;
	char *token = NULL;
	unsigned int idx = 0;
	opcode_token_t *new = NULL, *node = NULL;

	while ((result = get_opcode_token(line, &token, &idx)))
	{
		new = malloc(sizeof(opcode_token_t));
		if (new == NULL || result == -1)
		{
			if (token != NULL)
			{
				free(token);
			}
			free_opcode_args();
			malloc_error();
			exit(EXIT_FAILURE);
		}
		new->token = token;
		new->next = NULL;
		if (opcode_args == NULL)
		{
			opcode_args = new;
		}
		else
		{
			node = opcode_args;
			while (node->next)
			{
				node = node->next;
			}
			node->next = new;
		}
	}
}

/**
 * free_stack - free stack memory allocation
 * @stk: pointer to a stack
 */
void free_stack(stack_t **stk)
{
	stack_t *node = NULL, *temp = NULL;

	if (stk == NULL)
		return;
	node = *stk;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*stk = NULL;
}
