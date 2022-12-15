#include "monty.h"

validator_t rq = {0, 0};

/**
 * check_opcode - Check the found command
 * @command: coomand found in the line
 * @stack: Top of the stack
 * @n_line: Line that command was found
 * Return: 1 if command not found, return in opcode var if command was
 * found
 */

int check_opcode(char *command, stack_t **stack, size_t n_line)
{

	instruction_t opcodes[] = {
		{"rotr", rotr},
		{"rotl", rotl},
		{"pstr", pstr},
		{"pchar", pchar},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	size_t i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, n_line);
			return (rq.opcode);
		}
		i++;
	}
	printf("L%lu: unknown instruction %s\n", n_line, command);
	rq.opcode = 1;
	return (1);
}
