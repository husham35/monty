#include "monty.h"

/**
 * nop_opc - non-functional function
 * @stack: head of the stack
 * @ln_num: line number of opcode
 * Description: opcode nop doesn’t do anything
 * Return: void
 */
void nop_opc(stack_t **stack, unsigned int ln_num)
{
	(void)ln_num;
	(void)stack;
}
