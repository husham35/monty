#include "monty.h"

/**
 * div_opc - divides the second element by the top element of the stack
 * @stack: head of the stack
 * @ln_num: line number of the opcode
 * Description: divides the second element by the first element of the stack
 * Return: void
 */
void div_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *tmp = *stack;
	unsigned int k = 0, j = 0, len = 0;

	len = get_stack_size(*stack);

	if (len < 2)
		man_errs(DIV_ERROR, NULL, ln_num, NULL);

	k = tmp->n;

	if (k == 0)
		man_errs(ZERO_DIV_ERROR, NULL, ln_num, NULL);

	j = tmp->next->n;
	tmp->next->n = j / k;
	*stack = tmp->next;
	free(tmp);
}
