#include "monty.h"

/**
 * op_c_selection - selects monty instruction
 * @ins: The instruction to be executed
 * Description: selects appropriate opereation
 *				related to the Monty instruction
 * Return: ptr to function to be executed if function exists, else NULL
 */

void (*op_c_selection(char *ins))(stack_t **, unsigned int)
{
	instruction_t func_lists[] = {
		{"push_queue", set_push_queue},
		{"pchar", pchar_opc},
		{"div", div_opc},
		{"push", push_opc},
		{"pall", pall_opc},
		{"pint", pint_opc},
		{"swap", swap_opc},
		{"pstr", pstr_opc},
		{"rotl", rotl_opc},
		{"rotr", rotr_opc},
		{"pop", pop_opc},
		{"add", add_opc},
		{"nop", nop_opc},
		{"sub", sub_opc},
		{"mul", mul_opc},
		{"mod", mod_opc},
		{NULL, NULL}};
	int i = 0;

	while (func_lists[i].opcode)
	{
		if (strcmp(ins, func_lists[i].opcode) == 0)
			return (func_lists[i].f);
		i++;
	}

	return (NULL);
}
