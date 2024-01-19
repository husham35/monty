#include "monty.h"

/**
 * control_exec - handles the operations to be executed
 * @opc: operation code to be execute.
 * @d: data that comes with the instruction.
 * @ln: line number of the command in the bytecode file
 * @st_or_qu: indicates if the push operation should be stack or queue
 * Description: handles the operations to be executed by the interpreter
 * Return: 0 if successful, else err_code number
 */

int control_exec(char *opc, char *d, unsigned int ln, int st_or_qu)
{
	int op_stat = 0;
	void (*opcode_func)(stack_t **, unsigned int);

	if (strcmp(opc, "stack") == 0)
		return (STACK_METHOD);
	else if (strcmp(opc, "queue") == 0)
		return (QUEUE_METHOD);

	opcode_func = op_c_selection(opc);
	if (opcode_func)
	{
		if (strcmp(opc, "push") == 0)
		{
			op_stat = validate_push_data(d);
			if (op_stat == PUSH_ERROR)
				return (PUSH_ERROR);

			if (st_or_qu != 0 && st_or_qu == QUEUE_METHOD)
				opcode_func = op_c_selection("push_queue");

			opcode_func(&head, atoi(d));
		}
		else
			opcode_func(&head, ln);

		return (st_or_qu);
	}

	return (INVALID_ERROR);
}
