#ifndef _MAIN_H
#define _MAIN_H

#define _GNU_SOURCE

/** Header files */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer value of the node.
 * @prev: Pointer to the previous element of the stack (or queue).
 * @next: Pointer to the next element of the stack (or queue).
 *
 * Description: Doubly linked list node structure for stacks, queues,
 * LIFO, and FIFO.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function.
 * @opcode: The opcode as a string.
 * @f: Function pointer to handle the opcode.
 *
 * Description: Structure to associate an opcode with its handling function
 * for stacks and queues, supporting LIFO and FIFO operations.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct argument_s - Holds the execution context of the program.
 * @stream: File stream for reading input.
 * @line: Input line read from the stream.
 * @line_number: Current line number being processed.
 * @token: Array of tokens parsed from the input line.
 * @n_tokens: Number of tokens parsed from the input line.
 * @head: Pointer to the top of the stack.
 * @instruction: Pointer to the current instruction being executed.
 * @stack_length: Current length of the stack.
 */
typedef struct argument_s
{
	FILE *stream;
	char *line;
	unsigned int line_number;
	char **token;
	int n_tokens;
	stack_t *head;
	instruction_t *instruction;
	int stack_length;
} argument_t;


/** Function Prototypes */
void initialize_arguments(void);
int check_args(int argc);
void malloc_failed(void);
void get_stream(char *filename);
void free_arguments(void);
void get_instruction(void);
void invalid_instruction(void);
void free_tokens(void);
void close_stream(void);
void tokenize_line(void);
void run_command(stack_t **stack);
int is_number(char *str);
void free_all(void);

/** Function prototypes for opcodes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number, int n);
void pop_wrapper(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

extern argument_t *arguments;

#endif
