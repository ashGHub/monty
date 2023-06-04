#include "monty.h"

/* opcode command and its arguments, the head is the command */
opcode_token_t *opcode_args = NULL;
/* flag to set list mode: if stack or queue */
short LIST_MODE = STACK_MODE;

/**
 * main - entry point to monty bytecode inteprator
 * @argc: number of command line options
 * @argv: the command line options
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (inteprate_file(argv[1]));
}

/**
 * inteprate_file - inteprates a monty byte code file
 * @file_name: monty bytecode file path
 *
 * Return: 0 if successful, otherwise non-zero number
 */
int inteprate_file(char *file_name)
{
	size_t read = 0;
	char *line = NULL;
	FILE *file = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((read = get_line(&line, file)))
	{
		inteprate_line(line, &stack, ++line_number);
	}
	fclose(file);
	free_stack(&stack);
	if (line != NULL)
	{
		free(line);
	}
	return (0);
}

/**
 * inteprate_line - inteprates a monty bytecode opcode
 * @line: pointer to the line
 * @stk: pointer to stack
 * @line_number: opcode line number
 */
void inteprate_line(char *line, stack_t **stk, unsigned int line_number)
{
	void (*handle)(stack_t **, unsigned int) = NULL;

	free_opcode_args();
	if (is_comment(line))
		return;
	set_opcode_args(line);
	/* empty line */
	if (opcode_args == NULL)
	{
		return;
	}
	handle = get_opcode_handler(opcode_args->token);
	if (handle == NULL)
	{
		invalid_opcode(opcode_args->token, line_number);
		free(line);
		free_opcode_args();
		exit(EXIT_FAILURE);
	}
	if (is_push_opcode() && LIST_MODE != STACK_MODE)
	{
		/* only push opcode, needs the list in stack mode */
		change_list_mode(stk, STACK_MODE);
		handle(stk, line_number);
		/* revert the mode to current setting */
		change_list_mode(stk, LIST_MODE);
	}
	else
	{
		handle(stk, line_number);
	}
	free_opcode_args();
}

/**
 * is_push_opcode - checks if current opcode is push
 * Return: 1 if is push code, otherwise 0
 */
short is_push_opcode(void)
{
	return (strcmp(opcode_args->token, "push") == 0);
}
