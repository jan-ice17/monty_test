#include "monty.h"
/**
* free_stack - Print all values on the stack
* @stack: pointer to head of stack
* Return: Void
*/
void free_stack(stack_t *stack)
{
        while (stack)
        {
                stack_t *tmp = stack;
                stack = stack->next;
                free(tmp);
        }
}
