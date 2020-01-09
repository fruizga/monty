#include "monty.h"
/**
*sub - sub operation
*@stack: stack
*@line_number: line number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= aux;
}

/**
*mul - mul operation
*@stack: stack
*@line_number: line number
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= aux;
}

/**
*fdiv - division operation
*@stack: stack
*@line_number: line number
*/
void fdiv(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;

	if (aux == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n /= aux;
}

/**
*mod - modulo operation
*@stack: stack
*@line_number: line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;

	if (aux == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n %= aux;
}