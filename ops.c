#include "monty.h"

/**
 * multiplyn - Add toper two elements of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void multiplyn(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_bug(8, line_number, "mul");

	(*stack) = (*stack)->next;
	tot = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modulosn - Add toper two elements of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void modulosn(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_bug(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_bug(9, line_number);
	(*stack) = (*stack)->next;
	tot = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

