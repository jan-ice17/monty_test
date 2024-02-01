#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_number: line number in the file
 * @n: value to be pushed
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
    stack_t *new_node, *current_node = *stack;

    if (stack == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Create a new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "L%d: malloc failed\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->prev = NULL;
    new_node->n = n;
    new_node->next = *stack;
    if (*stack)
        current_node->prev = new_node;
    *stack = new_node;
}

/**
 * pall - Prints all values on the stack
 * @stack: pointer to head of stack
 *
 * Return: void
 */
void pall(stack_t **stack)
{
    stack_t *current_node = *stack;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}
