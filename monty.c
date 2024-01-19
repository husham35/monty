#include "monty.h"

stack_t *head = NULL;

/**
 * main - starting poing or programme
 * @argc: Number of arguments passed into the program.
 * @argv: Vector containing the arguments passed.
 * Description: main entry point of programme
 * Return: always 0.
 */

int main(int argc, char *argv[])
{
	FILE *monty_file = NULL;
	size_t cmd_len = 0;
	unsigned int line_number = 0;
	int command = 0, status = 0;
	char *filename = NULL, *opcode = NULL, *data = NULL, *line_read = NULL;

	filename = argv[1];
	get_num_args(argc);
	monty_file = open_file(filename);

	while ((command = getline(&line_read, &cmd_len, monty_file)) != -1)
	{
		line_number++;
		opcode = strtok(line_read, " \t\n");
		if (opcode)
		{
			if (opcode[0] == '#')
				continue;

			data = strtok(NULL, " \t\n");
			status = control_exec(opcode, data, line_number, status);

			if (status >= 100 && status < 300)
			{
				fclose(monty_file);
				man_errs(status, opcode, line_number, line_read);
			}
		}
	}

	set_stack_free();
	free(line_read);
	fclose(monty_file);
	return (0);
}
