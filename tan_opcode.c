#include "monty.h"
/**
*tan_opcode - select operation from structure
*@token: token
*@stack: stack
*@line_number: line_number
*/
void tan_opcode(char *token, stack_t **stack, unsigned int line_number)
{
int i;

instruction_t hugo_norzobia[] = {
{"push", push},
{"pall", pall},
{"add", add},
{"pop", pop},
{NULL, NULL}
};

for (i = 0; hugo_norzobia[i].opcode != NULL; i++)
{
if (strcmp(token, hugo_norzobia[i].opcode) == 0)
{
hugo_norzobia[i].f(stack, line_number);
return;
}
}

fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
/*liberar stack*/
exit(EXIT_FAILURE);
}
