#include "monty.h"

/**
 * rotl_opc - rotates the stack to the top
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: rotates the stack to the top,
 *				the top element of the stack becomes the last one
 *				and the second top element of the stack becomes the first one
 * Return: void
 */
void rotl_opc(stack_t **stack, unsigned int ln_num)
{
	unsigned int tmp = 0;
	stack_t *curr_item = *stack;
	(void)ln_num;

	if (curr_item && curr_item->next)
	{
		while (curr_item->next)
		{
			tmp = curr_item->n;
			curr_item->n = curr_item->next->n;
			curr_item->next->n = tmp;
			curr_item = curr_item->next;
		}
	}
}
