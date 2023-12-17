#include "monty.h"


/**
 * stack_add - Add node to stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * stack_print - Add node to stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: line number of  the opcode.
 */
void stack_print(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * poperup - Add node to stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void poperup(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_bug(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * printup - Print toper node of stack.
 * @stack: Pointer to a pointer pointing to toper node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printup(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_bug(6, line_number);
	printf("%d\n", (*stack)->n);
}

