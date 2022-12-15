#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <ctype.h>

#endif /* _MONTY_ */

#ifndef _MONTY_STRUCTS
#define _MONTY_STRUCTS

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure
 * for stack, queue algorithms - LIFO, FIFO.
 *
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
 * @f: function to the handle the opcode
 *
 * Description: opcode and its function for stack,
 * queue data structures (LIFO and FIFO)
 *
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif /* _MONTY_STRUCTS */

#ifndef _VALIDATOR_
#define _VALIDATOR_

/**
 * struct validator - return the value of opcode
 * @opcode: returns value of opcode
 * @queue_value: 1 if list is a queue, 0 if list is a stack
 *
 */
typedef struct validator
{
	int opcode;
	int queue_value;
} validator_t;

extern validator_t rq;

#endif /* VALIDATOR */

