#include "monty.h"

char *value = NULL;

/**
 * free_list - free the list
 * @head: pointer to a stack_t
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * main - main function
 * @argc: int
 * @argv: array
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char buffer[1024], *token = NULL;
	FILE *fp;
	int line_number = 0;
	void (*opcode_func)(stack_t **stack, unsigned int line_number);
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	fp = fopen(argv[1], "r");
	if (!fp)
=======
	free(lines);
}

/**
 *
 *
 *
 *
 */
void execute_lines(char** lines, int num_lines)
{
	int i= 0;
	char* arg;
	int data = atoi(arg);
	int lines_num = i + 1;
	char* token = strtok(lines, " ");

	for (i = 0; i < num_lines; i++)
>>>>>>> 707df782b7b892e9626ffbfb0dde0cc145698217
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, fp))
	{
		line_number++;
		token = strtok(buffer, "\n\t $");
		if (!token)
			continue;
<<<<<<< HEAD
		opcode_func = op_func(token);
		if (!opcode_func)
=======
		}
		if (strcmp(opcode, "push") == 0)
		{
			char* arg = strtok(NULL, "\n");

			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lines_num);
				exit(EXIT_FAILURE);
			}

			if (data == 0 && arg[0] != '0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", lines_num);
				exit(EXIT_FAILURE);
			}

			int top = 0;
			int line_number = 0;
			push(&top, data, line_number);
		}

		else if (strcmp(opcode, "pall") == 0)
		{
			pall(top);
		}
		else
>>>>>>> 707df782b7b892e9626ffbfb0dde0cc145698217
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		opcode_func(&head, line_number);
	}
	free_list(head);
	fclose(fp);
	return (0);
}
