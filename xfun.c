#include "monty.h"

/**
 * noper - nothing.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void noper(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * node_sw - Swap toper two elements of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void node_sw(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_bug(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * additionn - Add toper two elements of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void additionn(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_bug(8, line_number, "add");

	(*stack) = (*stack)->next;
	tot = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * subtractionn - Add toper two elements of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void subtractionn(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_bug(8, line_number, "sub");


	(*stack) = (*stack)->next;
	tot = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divisionn - Add toper two elements of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void divisionn(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_bug(8, line_number, "div");

	if ((*stack)->n == 0)
		more_bug(9, line_number);
	(*stack) = (*stack)->next;
	tot = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

