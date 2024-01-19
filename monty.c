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
	FILE *mf = NULL;
	size_t len_command = 0;
	unsigned int ln_num = 0;
	int cmd = 0, status = 0;
	char *file_name = NULL, *opc = NULL, *data = NULL, *ln_rd = NULL;

	file_name = argv[1];
	get_num_args(argc);
	mf = open_file(file_name);

	cmd = getline(&ln_rd, &len_command, mf);

	while ((getline(&ln_rd, &len_command, mf)) != -1)
	{
		ln_num++;
		opc = strtok(ln_rd, " \t\n");
		if (opc)
		{
			if (opc[0] == '#')
				continue;

			data = strtok(NULL, " \t\n");
			status = control_exec(opc, data, ln_num, status);

			if (status >= 100 && status < 300)
			{
				fclose(mf);
				man_errs(status, opc, ln_num, ln_rd);
			}
		}
	}

	set_stack_free();
	free(ln_rd);
	fclose(mf);
	return (0);
}
