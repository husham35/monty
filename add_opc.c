#include "monty.h"

/**
 * add_opc - adds two data elements of the stack
 * @stack: head of the stack
 * @ln_num: line number of the opcode
 * Description: adds the top two data elements (node) of the stack
 * Return: void
 */
void add_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *tmp = *stack;
	unsigned int k = 0, j = 0, len = 0;

	len = get_stack_size(*stack);

	if (len < 2)
		man_errs(ADD_ERROR, NULL, ln_num, NULL);

	k = tmp->n;
	j = tmp->next->n;
	tmp->next->n = k + j;
	*stack = tmp->next;
	free(tmp);
}
