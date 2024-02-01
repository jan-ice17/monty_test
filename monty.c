#include "monty.h"

/**
* push - Pushes an element to the stack
* @stack: pointer to head of stack
* @line_number: file's line number
*
* Return: address of new element
*/
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
}

/**
* pall - Print all values on the stack
* @stack: pointer to head of stack
* @line_number: file's line number
* Return: Void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void)line_number;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *ptr;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		ptr = h->next;
		if (ptr->next)
			ptr->next->prev = h;
		h->next = ptr->next;
		ptr->prev = NULL;
		ptr->next = h;
		h->prev = ptr;
		*stack = ptr;
	}
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


	if (h)
	{
		*stack = (h)->next;
		free(h);
	}
}

