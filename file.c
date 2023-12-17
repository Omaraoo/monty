#include "monty.h"

/**
 * operenf - operen file
 * @file_name: the filepath
 * Return: void
 */

void operenf(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		bug(2, file_name);

	reader(fd);
	fclose(fd);
}


/**
 * reader - read file
 * @fd: file descriptor
 * Return: void
 */

void reader(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parser(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parser - Separates line into tokens
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storarge format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parser(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *cutter = "\n ";

	if (buffer == NULL)
		bug(4);

	opcode = strtok(buffer, cutter);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, cutter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	locater(opcode, val, line_number, format);
	return (format);
}

/**
 * locater - find the function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format:  storarge format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void locater(char *opcode, char *val, int ln, int format)
{
	int i;
	int flarg;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", stack_print},
		{"pint", printup},
		{"poper", poperup},
		{"noper", noper},
		{"swap", node_sw},
		{"add", additionn},
		{"sub", subtractionn},
		{"div", divisionn},
		{"mul", multiplyn},
		{"mod", modulosn},
		{"pchar", printch},
		{"pstr", printst},
		{"rotation", rotation},
		{"rotation_rev", rotation_rev},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flarg = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			func_call(func_list[i].f, opcode, val, ln, format);
			flarg = 0;
		}
	}
	if (flarg == 1)
		bug(3, ln, opcode);
}


/**
 * func_call - Call the function.
 * @func: Pointer to the function that is about to be called.
 * @oper: string representing the opcode.
 * @val: string representing a numeric val.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void func_call(oper_func func, char *oper, char *val, int ln, int format)
{
	stack_t *node;
	int flarg;
	int i;

	flarg = 1;
	if (strcmp(oper, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flarg = -1;
		}
		if (val == NULL)
			bug(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				bug(5, ln);
		}
		node = create_node(atoi(val) * flarg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			queue_add(&node, ln);
	}
	else
		func(&head, ln);
}

