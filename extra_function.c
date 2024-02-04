#include "monty.h"

/* Checks if a string is a number */
int _isdigit(char *str)
{
    int i = 0;

    /* Check each character in the string */
    while (str[i] != '\0')
    {
        /* If the character is not a digit, return 0 (false) */
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }

    /* If all characters are digits, return 1 (true) */
    return (1);
}

/* Adds a new node to the stack */
void add_dnodeint(stack_t **stack, int value)
{
    stack_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Add the new node to the top of the stack */
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}


