#include "monty.h"

/**
 * pall - Print all values in the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line of the file the command was found
 *
 */

void pall(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	(void) n_line;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Print the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line of the file the command was found
 *
 */

void pint(stack_t **stack, unsigned int n_line)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @n_line: current line number
 *
 */

void pop(stack_t **stack, unsigned int n_line)
{
	stack_t *kill_node, *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		printf("L%u: can't pop an empty stack\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		kill_node = tmp;
		*stack = tmp->next;
		if (tmp != NULL)
			tmp->prev = NULL;
		free(kill_node);
	}
}

/**
 * swap - swap elemnts into the list
 * @stack: Double pointer to the top the stack
 * @n_line: The line of the file the command was found
 *
 */

void swap(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;
	int flag;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		flag = tmp->n;
		tmp->n = tmp->next->n;
		tmp->next->n = flag;
	}
}

/**
 * add - add the top 2 values of the stack, store sum in second position,
 * set *stack to second node, and remove top node
 * @stack: Double pointer to the top the stack
 * @n_line: The line of the file the command was found
 *
 */

void add(stack_t **stack, unsigned int n_line)
{
	stack_t *flag = *stack;

	if (flag == NULL || flag->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", n_line);
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		flag->next->n += flag->n;
		pop(stack, n_line);
	}
}
