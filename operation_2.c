#include "monty.h"

/**
 * set_stack_free - frees node
 * Description: fress all nodes in the stack memory
 * Return: void
 */

void set_stack_free(void)
{
	stack_t *curr_item = NULL;

	if (head)
	{
		curr_item = head;

		while (curr_item)
		{
			head = head->next;
			free(curr_item);
			curr_item = head;
		}
	}
}

/**
 * get_stack_size - returns stack size
 * @stack: head of the stack
 * Description: computes the number of elements in the stack
 * Return: size of stack
 */

unsigned int get_stack_size(stack_t *stack)
{
	stack_t *curr_item = stack;
	unsigned int len = 0;

	while (curr_item)
	{
		len++;
		curr_item = curr_item->next;
	}

	return (len);
}
