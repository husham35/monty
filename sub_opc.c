#include "monty.h"

/**
 * sub_opc - subtracts the top firs element of the stack
 *			from the second top element of the stack
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: subtracts the top element of the stack
 *				from the second top element of the stack
 * Return: void
 */
void sub_opc(stack_t **stack, unsigned int ln_num)
{
	unsigned int k = 0, j = 0, len = 0;
	stack_t *tmp = *stack;

	len = get_stack_size(*stack);

	if (len < 2)
		man_errs(SUB_ERROR, NULL, ln_num, NULL);

	k = tmp->n;
	j = tmp->next->n;
	tmp->next->n = j - k;
	*stack = tmp->next;
	free(tmp);
}
