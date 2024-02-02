#include "monty.h"


/**
 * push - Pushes an element to the stack.
 * @n: integer to be pushed
 *
 */
void push(const int n)
{
	stack_t *top = NULL;

	top = malloc(sizeof(*top));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (global->head == NULL)
	{
		top->n = n;
		top->prev = NULL;
		top->next = NULL;
		global->head = top;
		return;
	}
	(global->head)->prev = top;
	top->next = global->head;
	top->prev = NULL;
	top->n = n;
	global->head = top;
}