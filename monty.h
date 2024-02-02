#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globe_s - global resources like line, line numer, stack, etc
 * @file: the file to run monty instructions from
 * @head: the stack
 * @line: line buffer
 * @line_no: current execution line number
 * @token_list: list of token
 *
 * Description: holds the line buffer, line no, stacks, tokens
 * for the program
 */
typedef struct globe_s
{
	struct stack_s *head;
	FILE *file;
	char *line;
	unsigned int line_no;
	char **token_list;
} globe_t;


extern globe_t *global;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(const int);
void f_pall(stack_t **head, unsigned int counter);
void pint(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void divide(stack_t **, unsigned int);
int interprete(char **, unsigned int);
void allocate_memory(void);
void free_stack(void);
void free_memory(void);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif