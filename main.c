#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    unsigned int line_number = 1;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1) {
        char *token = strtok(line, " \t\n");
        instruction_t instructions[] = {
            {"push", push},
            {"pall", pall},
            {NULL, NULL}
        };

        int i = 0;
        while (instructions[i].opcode != NULL) {
            if (strcmp(token, instructions[i].opcode) == 0) {
                instructions[i].f(&stack, line_number);
                break;
            }
            i++;
        }

        if (instructions[i].opcode == NULL) {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    free(line);
    fclose(fp);
    return 0;
}
