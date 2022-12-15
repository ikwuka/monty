#include "monty.h"

/**
 * kill_free - free the memory and exit
 * @stack: top of the stack.
 * @file: file opened.
 * @line: line found using getline function.
 *
 * Return: Void function.
 */

void kill_free(char *line, FILE *file, stack_t *stack)
{
	kill_stack(stack);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * kill_stack - free all nodes of the stack
 * @stack: top of the stack
 *
 * Return: Void function.
 */

void kill_stack(stack_t *stack)
{
	stack_t *kill_node;

	while (stack != NULL)
	{
		kill_node = stack;
		stack = stack->next;
		free(kill_node);
	}
}
