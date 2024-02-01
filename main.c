#include "monty.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
};

/**
 * main - monty interperter
 * @ac: the number of arguments
 * @av: the arguments
 * Return: void
 */
int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty <file>\n");
                exit(EXIT_FAILURE);
        }

        FILE *fp = fopen(argv[1], "r");
        if (!fp)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        stack_t *stack = NULL;
        unsigned int line_number = 0;
        char line[MAX_LINE_LENGTH];

        while (fgets(line, MAX_LINE_LENGTH, fp))
        {
                line_number++;
                char *token = strtok(line, " \t\n");
                if (!token)
                        continue;

                instruction_t *instruction = instructions;
                while (instruction->opcode)
                {
                        if (strcmp(instruction->opcode, token) == 0)
                        {
                                char *arg = strtok(NULL, " \t\n");
                                instruction->f(&stack, line_number, arg);
                                break;
                        }
                        instruction++;
                }

                if (!instruction->opcode)
                {
                        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
                        exit(EXIT_FAILURE);
                }
        }

        fclose(fp);
        free_stack(stack);
        return 0;
}
