#include "monty.h"

/**
 * mod_opc - computes the modulo the second top element
 *		 of the stack by the top element of the stack
 * @stack: The head of the stack
 * @ln_num: line number of the opcode
 * Description: Computes the rest of the division of the second top element
 *		 of the stack by the top element of the stack
 * Return: void
 */
void mod_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp = *stack;
	unsigned int k = 0, j = 0, len = 0;

	len = get_stack_size(*stack);

	if (len < 2)
		man_errs(MODL_ERROR, NULL, ln_num, NULL);

	k = temp->n;

	if (k == 0)
		man_errs(ZERO_DIV_ERROR, NULL, ln_num, NULL);

	j = temp->next->n;
	temp->next->n = j % k;
	*stack = temp->next;
	free(temp);
}
