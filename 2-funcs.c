#include "monty.h"

/**
 * pstr - Print out every element of the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line that the command was found in the file
 */

void pstr(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;
	(void) n_line;
	if (*stack != NULL)
	{
		tmp = *stack;
		while (tmp != NULL && tmp->n > 0 && tmp->n <= 127)
		{
			putchar(tmp->n);
			tmp = tmp->next;
		}
	}
	putchar('\n');
}

/**
 *rotl - take the top element an put it on the bottom
 *@stack: Double pointer to the top of the stack
 *@n_line: The line that the command was found
 */

void rotl(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp, *node1, *node2;

	(void) n_line;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = node1 = *stack;
		node2 = tmp->next;

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = node1;
		node1->prev = tmp;
		node1->next = NULL;
		node2->prev = NULL;
		*stack = node2;
	}
}

/**
 * rotr - The last element of the stack become top element of the stack
 * @stack: Double pointer to the top of the stack
 * @n_line: The line that the command was found
 */

void rotr(stack_t **stack, unsigned int n_line)
{
	stack_t *node1, *node2;
	(void) n_line;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		node1 = *stack;
		while (node1->next != NULL)
		{
			node1 = node1->next;
		}
		node2 = node1->prev;
		node2->next = NULL;
		node1->next = *stack;
		node1->prev = NULL;
		(*stack)->prev = node1;
		*stack = node1;
	}
}
