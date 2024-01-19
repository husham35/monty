#include "monty.h"

/**
 * pop_opc - removes the top element of the stack
 * @stack: the head of the stack
 * @ln_num: line number of opcode
 * Description: removes the top element of the stack
 * Return: void
 */
void pop_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr_item = *stack, *tmp = NULL;

	if (*stack == NULL)
		man_errs(POP_ERROR, NULL, ln_num, NULL);

	tmp = curr_item;
	if (curr_item->next)
	{
		curr_item = curr_item->next;
		curr_item->prev = tmp->prev;
		*stack = curr_item;
	}
	else
	{
		*stack = NULL;
	}

	free(tmp);
}
