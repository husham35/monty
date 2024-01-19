#include "monty.h"

/**
 * pstr_opc - prints the string starting at the top of the stack
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: prints the string starting at the top of the stack
 *				followed by \n
 * Return: void
 */
void pstr_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr_item = *stack;
	(void)ln_num;

	while (curr_item)
	{
		if (curr_item->n == 0 || curr_item->n < 0 || curr_item->n > 127)
			break;

		printf("%c", curr_item->n);
		curr_item = curr_item->next;
	}

	printf("\n");
}
