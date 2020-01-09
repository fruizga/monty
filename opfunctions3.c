#include "monty.h"
/**
*fpstr - pstr operation
*@stack: stack
*@line_number: line number
*/
void fpstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	UNUSED(line_number);
	if (!(*stack) || externalvar.varext == 0 || !stack)
	{
		printf("\n");
		return;
	}
	aux = *stack;
	while (aux && isascii(aux->n) && aux->n)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}

/**
*swap - swap items
*@stack: stack
*@line_number: line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = aux->next;
	aux->prev = NULL;
	(*stack)->prev = aux;

	if (aux->next)
		aux->next->prev = *stack;

	aux->next = *stack;
	(*stack) = (*stack)->prev;
}

/**
 * nop - It is a lazy function
 * @stack: stack
 * @line_number: line_number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
*pchar - pchar fuction
*@stack: stack
*@line_number: line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (isascii(externalvar.varext))
	{printf("%c\n", externalvar.varext); }
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}