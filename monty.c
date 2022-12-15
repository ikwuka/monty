#include "monty.h"

/**
 * main - run opcode for commands
 * @argc: number of arguments
 * @argv: array of strings passed to the program
 *
 * Return: 1 if reaches end of the file, exit "EXIT_FAILURE" of opccode fails
 *
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *command;
	size_t size = 0, n_line = 1;
	stack_t *stack = NULL;
	ssize_t read = 0;

	if (argc != 2)
		printf("USAGE: monty file\n"), exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read = getline(&line, &size, file);

	while (read != -1)
	{
		command = find_co(line, &stack, n_line);
		if (strcmp(command, "nop"))
			check_opcode(command, &stack, n_line);

		if (rq.opcode != 0)
			kill_free(line, file, stack);

		n_line++;
		read = getline(&line, &size, file);
	}
	kill_stack(stack);
	free(line);
	fclose(file);
	return (0);
}

/**
 * find_co - find the given opcode
 * @line: line in monty file
 * @stack: top of stack or queue
 * @n_line: line number into the file
 *
 * Return: Name of the command found
 *
 */

char *find_co(char *line, stack_t **stack, unsigned int n_line)
{
	char *command, *pusharg;

	command = strtok(line, " \n\t");
	if (command == NULL || command[0] == '#')
		command = "nop";
	if (strcmp(command, "push") == 0)
	{
		command = "nop";
		pusharg = strtok(NULL, " \n\t");
		if (isnumber(pusharg) == 0)
		{
			if (rq.queue_value == 0)
				add_node(stack, atoi(pusharg));
			else
				add_node_end(stack, atoi(pusharg));
		}
		else
		{
			printf("L%u: usage: push integer\n", n_line);
			rq.opcode = 1;
			return (command);
		}
	}
	if (strcmp(command, "stack") == 0)
	{
		command = "nop";
		rq.queue_value = 0;
		return (command);
	}
	if (strcmp(command, "queue") == 0)
	{
		command = "nop";
		rq.queue_value = 1;
		return (command);
	}
	return (command);
}

/**
 * isnumber - checks if given argument to push is integer or not
 * @str: String argument found after push opcode
 *
 * Return: 1 if isn't a integer, 0 on Success
 *
 */

int isnumber(char *str)
{
	int i;

	if (str == NULL)
		return (1);

	i = 0;
	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

/**
 * add_node - Add a node to the top of the list
 * @stack: top of the stack
 * @value: value to assign to the new node
 *
 */

void add_node(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		if (*stack != NULL)
			(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->n = value;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

/**
 * add_node_end - Add a node to the end of the list
 * @stack: Double pointer to the top of the stack
 * @value: The value to assign to the new node
 *
 */

void add_node_end(stack_t **stack, int value)
{
	stack_t *new_node;
	stack_t *flag;

	flag = *stack;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		rq.opcode = 1;
	}
	if (rq.opcode != 1)
	{
		while (flag != NULL && flag->next != NULL)
			flag = flag->next;
		new_node->n = value;
		new_node->next = NULL;
		new_node->prev = flag;
		if (flag != NULL)
			flag->next = new_node;
		else
			*stack = new_node;
	}
}
