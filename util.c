#include "monty.h"

/**
 * safe_atoi - parses integer from a string in safe way
 * @str: string to parse
 * @result: where the parsed value is going to be set
 *
 * Return: 1 if successful, otherwise 0 on error
 */
short safe_atoi(char *str, int *result)
{
	char *ptr;
	short base_10 = 10;

	if (str == NULL || result == NULL)
	{
		return (0);
	}
	*result = strtol(str, &ptr, base_10);
	if (str == ptr || *ptr != '\0')
	{
		return (0);
	}
	return (1);
}

/**
 * resize - resize given memory
 * @mem: pointer to the memory
 * @new_size: size for the new memory
 *
 * Return: pointer to the new memory, else NULL on failure
 */
char *resize(char *mem, int new_size)
{
	char *new;

	new = malloc(sizeof(char) * new_size);
	if (new == NULL)
	{
		if (mem != NULL)
		{
			free(mem);
		}
		malloc_error();
		exit(EXIT_FAILURE);
	}
	if (mem == NULL)
	{
		return (new);
	}
	strcpy(new, mem);
	free(mem);
	return (new);
}

/**
 * is_comment - checks given string is a comment or not
 * @str: string
 *
 * Return: 1 if is comment, otherwise 0
 */
short is_comment(char *str)
{
	unsigned int idx = 0;
	char *delim = EMPTY_DELIMS;

	skip_delimiter(str, &idx, delim);
	return (str && str[idx] == '#');
}

/**
 * get_line - read a line from a file
 * @line: line pointer to set the new value
 * @file: pointer to a file
 *
 * Description: the pointer to line will be resized
 *              so, you only need to free it on
 *              your last call
 *
 * Return: total read bytes if successful,
 *	   0 if end of file or error
 */
size_t get_line(char **line, FILE *file)
{
	short has_overflow = 0;
	size_t read, total_read = 0;
	char buffer[LINE_BUFFER_LIMIT];
	unsigned int buffer_limit = LINE_BUFFER_LIMIT;

	while (fgets(buffer, sizeof(buffer), file))
	{
		read = strlen(buffer);
		total_read += read;
		has_overflow = total_read > buffer_limit;
		if (*line == NULL || has_overflow)
		{
			*line = resize(*line, (buffer_limit * 2));
		}
		memcpy(*line + total_read - read, buffer, read);
		if (buffer[read - 1] == '\n')
		{
			(*line)[total_read] = '\0';
			return (total_read);
		}
	}
	return (0);
}

/**
 * get_opcode_handler - get the appropriate opcode handler function
 * @opcode: opcode
 *
 * Return: pointer to the opcode handler function
 */
void (*get_opcode_handler(char *opcode))(stack_t **, unsigned int)
{
	instruction_t handlers[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{NULL, NULL}
	};
	int idx = 0;

	while (handlers[idx].opcode)
	{
		if (strcmp(handlers[idx].opcode, opcode) == 0)
			return (handlers[idx].f);
		idx++;
	}
	return (NULL);
}
