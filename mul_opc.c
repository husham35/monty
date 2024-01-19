#include "monty.h"

/**
 * mul_opc - multiplies first first and second elements in a stack
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: computes product of the second top element of the stack
 *	with the top element of the stack
 * Return: void
 */
void mul_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *tmp = *stack;
	unsigned int k = 0, j = 0, len = 0;

	len = get_stack_size(*stack);

	if (len < 2)
		man_errs(MULT_ERROR, NULL, ln_num, NULL);

	k = tmp->n;
	j = tmp->next->n;
	tmp->next->n = j * k;
	*stack = tmp->next;
	free(tmp);
}
