#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <ctype.h>

#endif /* _MONTY_ */

#ifndef _MONTY_STRUCT_ONE_
#define _MONTY_STRUCT_ONE_

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

#endif /* _MONTY_STRUCT_ONE */