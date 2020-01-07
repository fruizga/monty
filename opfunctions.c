#include "monty.h"
/**
*push - add new node
*@stack: stack
*@line_number: line number
*/
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_nodo = NULL;

if (!stack)
{
fprintf(stderr, "L%d: unknown stack\n", line_number);
	exit(EXIT_FAILURE);
}
new_nodo = malloc(sizeof(size_t));
if (new_nodo == NULL)
{
fprintf(stderr, "Error: malloc failed\n"/*), FrStack(stack, line_number*/);
	exit(EXIT_FAILURE);
}

new_nodo->n = externalvar.varext;
new_nodo->next = *stack;
new_nodo->prev = NULL;
if (*stack)
{
(*stack)->prev = new_nodo;
}

*stack = new_nodo;
}

/**
*pall - prints all elements of stack
*@stack: stack
*@line_number: line number
*/

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *printstack;

if (!stack)
{
fprintf(stderr, "L%d: invalid stack\n", line_number);
	exit(EXIT_FAILURE);
}

printstack = *stack;

while (printstack)
{
printf("%d\n", printstack->n);
printstack = printstack->next;
}

}

/**
*add - add operation
*@stack: stack
*@line_number: line number
*/

void add(stack_t **stack, unsigned int line_number)
{
int sum;

if (!stack || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

sum = (*stack)->n;
pop(stack, line_number);
(*stack)->n += sum;
}

/**
*pop - delete element
*@stack: stack
*@line_number: line number
*/

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *aux = *stack;

if (!stack)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

*stack = (*stack)->next;
free(aux);

if (*stack)
{
(*stack)->prev = NULL;
}
}
