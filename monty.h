#ifndef __MONTY_H__
#define __MONTY_H__

#define VALID_DATA 0
#define MIN_ARGS 2

#define INVALID_ERROR 100
#define MALL_ERROR 101
#define INVALID_PARAM_ERROR 102 /* MIGHT BE DELETED */
#define STACK_METHOD 300
#define QUEUE_METHOD 301

#define USAGE_ERROR 200
#define PUSH_ERROR 201
#define PINT_ERROR 202
#define POP_ERROR 203
#define SWAP_ERROR 204
#define ADD_ERROR 205
#define SUB_ERROR 206
#define DIV_ERROR 207
#define ZERO_DIV_ERROR 208
#define MULT_ERROR 209
#define MODL_ERROR 210
#define PCHAR_ERROR_1 211
#define PCHAR_ERROR_2 212

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;

	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;

	void (*f)(stack_t **stack, unsigned int ln_num);

} instruction_t;

extern stack_t *head;

int control_exec(char *, char *, unsigned int, int);

void man_errs(int, char *, unsigned int, char *);

void mall_errs(int, char *, unsigned int);

void extra_errs(int, unsigned int);

void (*op_c_selection(char *s))(stack_t **, unsigned int);

void opc_errs(int, unsigned int);

void push_opc(stack_t **, unsigned int);

void get_rd_perm(char *);

unsigned int get_stack_size(stack_t *);

int validate_push_data(char *);

void get_num_args(int);

int validate_digits(char *);

void set_stack_free(void);

/* ops related funcs */

void div_opc(stack_t **, unsigned int);

void pchar_opc(stack_t **, unsigned int);

void swap_opc(stack_t **, unsigned int);

void set_push_queue(stack_t **, unsigned int);

void pall_opc(stack_t **, unsigned int);

void pint_opc(stack_t **, unsigned int);

void pstr_opc(stack_t **, unsigned int);

void rotl_opc(stack_t **, unsigned int);

void rotr_opc(stack_t **, unsigned int);

void pop_opc(stack_t **, unsigned int);

void add_opc(stack_t **, unsigned int);

void nop_opc(stack_t **, unsigned int);

void sub_opc(stack_t **, unsigned int);

void mul_opc(stack_t **, unsigned int);

void mod_opc(stack_t **, unsigned int);

FILE *open_file(char *);

#endif /* __MONTY_H__ */
