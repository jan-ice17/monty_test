#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *token = strtok(NULL, " \t\n");

    if (token == NULL) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(token);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
