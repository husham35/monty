#include "monty.h"

/**
 * push_opc - inserts a new node at the beginning of a stack
 * @stack: head of the stack node
 * @d: data part to push on to the stack node
 * Description: inserts a new node at the beginning of a stack
 * Return: void
 */
void push_opc(stack_t **stack, unsigned int d)
{
	stack_t *new_nd = NULL;

	new_nd = malloc(sizeof(stack_t));
	if (!new_nd)
		man_errs(MALL_ERROR, NULL, 0, NULL);

	new_nd->n = d;
	if (*stack)
	{
		new_nd->next = *stack;
		new_nd->prev = (*stack)->prev;
		(*stack)->prev = new_nd;
		*stack = new_nd;
		return;
	}

	new_nd->next = *stack;
	new_nd->prev = NULL;
	*stack = new_nd;
}

/**
 * set_push_queue - appends a new node at the end of the stack
 * @stack: head of the stack
 * @d: value to append to stack
 * Description: creates a a new node space in the stack struct in order
 *				to insert a new itme
 * Return: void
 */
void set_push_queue(stack_t **stack, unsigned int d)
{
	stack_t *curr_item = NULL, *new_nd = NULL;

	new_nd = malloc(sizeof(stack_t));
	if (!new_nd)
		man_errs(MALL_ERROR, NULL, 0, NULL);

	new_nd->n = d;
	if (*stack)
	{
		curr_item = *stack;
		while (curr_item->next != NULL)
			curr_item = curr_item->next;

		new_nd->next = NULL;
		new_nd->prev = curr_item;
		curr_item->next = new_nd;
		return;
	}

	new_nd->next = *stack;
	new_nd->prev = NULL;
	*stack = new_nd;
}
