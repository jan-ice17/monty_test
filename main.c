#include "monty.h"
#include <string.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
    FILE *fp;
    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token = strtok(line, " \t\n");
        int i = 0;

        while (instructions[i].opcode != NULL) {
            if (strcmp(token, instructions[i].opcode) == 0) {
                instructions[i].f(&stack, line_number);
                break;
            }
            i++;
        }
        line_number++;
    }

    fclose(fp);
    return (0);
}

