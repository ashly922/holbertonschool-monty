#include "monty.h"

#define MAX_LINE_LENGTH 1024
/**
 * read_file - fuction takes a filename as input, opens and reads its contents
 * and returns it as an array of strings with each string representing a
 * single line.
 * @filename - the name of the file to read
 * @num_lines - pointer to an integer that will stores the number of lines
 *
 * Return: An Array of strings Representing the lines in the file
 *
 */
char** read_file(const char* filename, int* num_lines)
{
	int count = 0;
	char buffer[MAX_LINE_LENGTH];
	char** lines = (char**)malloc(count * sizeof(char*));
	int i = 0;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, MAX_LINE_LENGTH, fp))
	{
		count++;
	}
	if(lines == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	while (fgets(buffer, MAX_LINE_LENGTH, fp))
	{
		int len = strlen(buffer);
		if (buffer[len-1] == '\n')
		{
			buffer[len-1] = '\0';
		}

		lines[i] = (char*) malloc((len+1) * sizeof(char));
		if (lines[i] == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(lines[i], buffer);
		i++;
	}
	*num_lines = count;
	fclose(fp);
	return (lines);
}
/**
 *
 *
 *
 *
 *
 */
void free_lines(char** lines, int num_lines)
{
	int i;

	for (i = 0; i < num_lines; i++)
	{
		free(lines[i]);
	}
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
	int i;
	int data = atoi(arg);
	int lines_num = i + 1;
	char* token = strtok(lines_num, " ");

	for (i = 0; i < num_lines; i++)
	{
		char* line = lines[i];

		if (strlen(line) == 0)
		{
			continue;
		}
		if (token == NULL)
		{
			continue;
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

			push(&top, data, line_number);
		}

		else if (strcmp(opcode, "pall") == 0)
		{
			pall(top);
		}
		else
		{
			printf("L%d: unknown instruction %s\n",lines_num, opcode);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *
 *
 *
 *
 */
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char* filename = argv[1];
	int num_lines;
	char** lines = read_file(filename, &num_lines);

	execute_lines(lines, num_lines);

	free_lines(lines, num_lines);
	return (0);
}
