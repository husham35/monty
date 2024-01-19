#include "monty.h"

/**
 * pint_opc - prints the value at the top of the stack
 * @stack: head of the stack
 * @ln_num: line number of the opcode
 * Description: prints value at the top of the stack, followed by a \n
 * Return: void
 */
void pint_opc(stack_t **stack, unsigned int ln_num)
{
	if (*stack == NULL)
		man_errs(PINT_ERROR, NULL, ln_num, NULL);

	printf("%d\n", (*stack)->n);
}
