#include "monty.h"

/**
 * rotr_opc - rotates the stack to the bottom
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: rotates the stack to the bottom,
 *				the last element of the stack becomes
 *				the top element of the stack
 * Return: void
 */
void rotr_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *last_item = NULL;
	(void)ln_num;

	if (*stack && (*stack)->next)
	{
		last_item = *stack;

		while (last_item->next != NULL)
			last_item = last_item->next;

		last_item->prev->next = NULL;
		last_item->next = *stack;
		*stack = last_item;
	}
}
