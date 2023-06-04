#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_BUFFER_LIMIT 100
#define EMPTY_DELIMS " \n\t\a\b"

/**
 * struct opcode_token_s - singly linked list representation
 *                         of opcode and its arguments
 * @token: token value
 * @next: points to the next token
 */
typedef struct opcode_token_s
{
	char *token;
	struct opcode_token_s *next;
} opcode_token_t;

/* global variables */
/* opcode command and its arguments, the head is the command */
extern opcode_token_t *opcode_args;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 *              for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 *              for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main functions */
void inteprate_line(char *line, stack_t **stk, unsigned int line_number);
int inteprate_file(char *file_name);

/* help functions */
void invalid_opcode(char *code, int n);
void malloc_error(void);
void free_opcode_args(void);
void set_opcode_args(char *line);
void free_stack(stack_t **stk);

/* util functions */
short safe_atoi(char *str, int *result);
char *resize(char *mem, int new_size);
short is_comment(char *str);
size_t get_line(char **line, FILE *file);
void (*get_opcode_handler(char *opcode))(stack_t **, unsigned int);

/* util 2 functions */
short is_delim(char ch, char *delim);
void skip_delimiter(char *str, unsigned int *idx, char *delim);
short get_token_len(char *str, unsigned int idx, char *delim);
short get_opcode_token(char *str, char **token, unsigned int *idx);

/* stack functions */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* stack 2 functions */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);

/** stack 3 functions */
void monty_mod(stack_t **stack, unsigned int line_number);

#endif
