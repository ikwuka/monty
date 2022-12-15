#include "monty.h"

/**
 * sub - Substract the top element of the stack
 * @stack: of the stack
 * @n_line: the line the command was found
 */

void sub(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		tmp->next->n -= tmp->n;
		pop(stack, n_line);
	}
}

/**
 * _div - Divide the second element of the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line the command was found in the monty file
 **/
void _div(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", n_line);
		rq.opcode = 1;
	}
	if (tmp != NULL && rq.opcode != 1 && tmp->n == 0)
	{
		printf("L%u: division by zero\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		tmp->next->n /= tmp->n;
		pop(stack, n_line);
	}
}

/**
 * mul - Multiply the top two values of the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line the command was found in the monty file
 */

void mul(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		tmp->next->n *= tmp->n;
		pop(stack, n_line);
	}
}

/**
 * mod - Mod the second element of the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line the command was found in the monty file
 */

void mod(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", n_line);
		rq.opcode = 1;
	}
	if (tmp != NULL && tmp->n == 0 && rq.opcode != 1)
	{
		printf("L%u: division by zero\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		tmp->next->n %= tmp->n;
		pop(stack, n_line);
	}
}

/**
 * pchar - Print out the element of the code
 * @stack: Double pointer to the top of the stack
 * @n_line: The line that the command was found in the file
 */

void pchar(stack_t **stack, unsigned int n_line)
{
	if (*stack != NULL)
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
		{
			printf("L%u: can't pchar, value out of range\n",
			       n_line);

			rq.opcode = 1;
		}
		if (rq.opcode == 0)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
	}
	else
	{
		printf("L%u: can't pchar, stack empty\n", n_line);
		rq.opcode = 1;
	}
}
