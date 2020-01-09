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
{"pint", pint},
{"sub", sub},
{"mul", mul},
{"div", fdiv},
{"mod", mod},
{"swap", swap},
{"pchar", pchar},
{"pstr", fpstr},
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
freestack(stack, line_number);
exit(EXIT_FAILURE);
}
