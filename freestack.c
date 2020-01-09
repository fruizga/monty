#include "monty.h"

/**
 * freestack - Frees Stack
 * @stack: stack
 * @line_number: line-number
 * Return: void
 */
void freestack(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{return; }
	while (*stack)
	{pop(stack, line_number); }
}