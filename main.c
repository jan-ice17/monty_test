#include "monty.h"
#include <stdio.h>
#include <string.h>

/* Declare variables at the beginning */
FILE *fp;
stack_t *stack;
char *line;
size_t len = 0;
int read;
unsigned int line_number = 1;

int main(int argc, char *argv[])
{
    /* Check for correct number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty bytecode file */
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Initialize the stack */
    stack = NULL;

    /* Process each line of the bytecode file */
    while ((read = getline(&line, &len, fp)) != -1)
    {
        /* Tokenize the line to extract the opcode and argument */
        char *opcode = strtok(line, " \t\n");
        int n = 0;  /* Initialize argument for opcodes that require it */
        if (opcode)
        {
            char *arg = strtok(NULL, " \t\n");
            if (arg)
            {
                n = atoi(arg);
            }
        }

        /* Call the appropriate function based on the opcode */
        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number, n);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        /* Add more cases for other Monty opcodes here */
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    /* Free allocated memory */
    free(line);
    fclose(fp);

    return 0;
}
