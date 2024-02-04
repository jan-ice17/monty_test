#include "monty.h"

/*Function Prototypes*/
int _isdigit(char *str);
void add_dnodeint(stack_t **stack, int value);

void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int value;

    token = strtok(NULL, " \t\n");
    if (token == NULL || _isdigit(token))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    value = atoi(token);
    add_dnodeint(stack, value);
}
