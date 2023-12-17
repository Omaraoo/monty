#include "monty.h"

/**
 * printch - Print Ascii val.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printch(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_bug(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_bug(10, line_number);
	printf("%c\n", ascii);
}

/**
 * printst - Print string.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void printst(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotation - Rotates first node of stack to bottom.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotation(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotation_rev - Rotate last node of stack to toper.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotation_rev(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

