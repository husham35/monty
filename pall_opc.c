#include "monty.h"

/**
 * pall_opc - prints all the values on the stack starting from the top
 * @stack: the head of the stack
 * @ln_num: ;ine number of the opcode
 * Description: prints all the values on the stack,
 *				starting from the top of the stack
 * Return: void
 */
void pall_opc(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr_val = NULL;
	(void)ln_num;

	if (*stack)
	{
		curr_val = *stack;
		while (curr_val)
		{
			printf("%d\n", curr_val->n);
			curr_val = curr_val->next;
		}
	}
}
