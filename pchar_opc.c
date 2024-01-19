#include "monty.h"

/**
 * pchar_opc - prints character in a stack
 * @stack: the head of the stack
 * @ln_num: line number of opcode
 * Description: prints the char at the top of the stack, followd by a new line
 * Return: void
 */
void pchar_opc(stack_t **stack, unsigned int ln_num)
{
	if (*stack == NULL)
		man_errs(PCHAR_ERROR_2, NULL, ln_num, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		man_errs(PCHAR_ERROR_1, NULL, ln_num, NULL);
}
