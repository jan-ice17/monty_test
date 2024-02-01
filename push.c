#include "monty.h"

/**
* push - Pushes an element to the stack
* @stack: pointer to head of stack
* @line_number: file's line number
*
* Return: address of new element
*/
void push(stack_t **stack, unsigned int line_number)
{
        if (!*stack)
        {
                *stack = malloc(sizeof(stack_t));
                if (!*stack)
                {
                        fprintf(stderr, "Error: malloc failed\n");
                        exit(EXIT_FAILURE);
                }
                (*stack)->n = atoi(global.arg);
                (*stack)->prev = NULL;
                (*stack)->next = NULL;
                return;
        }

        stack_t *new = malloc(sizeof(stack_t));
        if (!new)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new->n = atoi(global.arg);
        new->next = *stack;
        (*stack)->prev = new;
        new->prev = NULL;
        *stack = new;
}



