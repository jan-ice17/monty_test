#include "monty.h"
void pall(stack_t **stack) {
    if (*stack == NULL) {
        return;
    }

    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}