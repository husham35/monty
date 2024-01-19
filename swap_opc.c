#include "monty.h"

/**
 * swap_opc - swaps the top two elements of the stack
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: swaps the top two elements of the stack
 * Return: void
 */
void swap_opc(stack_t **stack, unsigned int ln_num)
{
	unsigned int len = 0, tmp = 0;

	len = get_stack_size(*stack);

	if (len < 2)
		man_errs(SWAP_ERROR, NULL, ln_num, NULL);

	if (*stack)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
