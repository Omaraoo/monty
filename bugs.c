#include "monty.h"

/**
 * bug - Prints bugs messarges by their code.
 * @bugs_code: The bugs codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be operened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for poper.
 * (8) => When stack is too short for opereration.
 */
void bug(int bugs_code, ...)
{
	va_list arg;
	char *oper;
	int lin_no;

	va_start(arg, bugs_code);
	switch (bugs_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "bugs: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			lin_no = va_arg(arg, int);
			oper = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lin_no, oper);
			break;
		case 4:
			fprintf(stderr, "bugs: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * more_bug - handles bugss.
 * @bugs_code: The bugs codes are:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for poper.
 * (8) => When stack is too short for opereration.
 * (9) => Division by zero.
 */
void more_bug(int bugs_code, ...)
{
	va_list arg;
	char *op;
	int lin_no;

	va_start(arg, bugs_code);
	switch (bugs_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			lin_no = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lin_no, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * string_bug - handles bugs.
 * @bugs_code: The following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_bug(int bugs_code, ...)
{
	va_list arg;
	int lin_no;

	va_start(arg, bugs_code);
	lin_no = va_arg(arg, int);
	switch (bugs_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, val out of range\n", lin_no);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lin_no);
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

