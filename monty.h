#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*oper_func)(stack_t **, unsigned int);

/*opereration file */
void operenf(char *file_name);
int parser(char *buffer, int line_number, int format);
void reader(FILE *);
int tailor(FILE *);
void locater(char *, char *, int, int);

/*opereration Stack */
stack_t *create_node(int n);
void node_free(void);
void stack_print(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue_add(stack_t **, unsigned int);

void func_call(oper_func, char *, char *, int, int);

void printup(stack_t **, unsigned int);
void poperup(stack_t **, unsigned int);
void noper(stack_t **, unsigned int);
void node_sw(stack_t **, unsigned int);

/*opereration MATh*/
void additionn(stack_t **, unsigned int);
void subtractionn(stack_t **, unsigned int);
void divisionn(stack_t **, unsigned int);
void multiplyn(stack_t **, unsigned int);
void modulosn(stack_t **, unsigned int);

/*opererations String */
void printch(stack_t **, unsigned int);
void printst(stack_t **, unsigned int);
void rotation(stack_t **, unsigned int);

/*bugs*/
void bug(int bugs_code, ...);
void more_bug(int bugs_code, ...);
void string_bug(int bugs_code, ...);
void rotation_rev(stack_t **, unsigned int);

#endif

