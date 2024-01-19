#include "monty.h"

/**
 * man_errs - manages the printing of errors
 * @err_num: defined error code.
 * @opc: operation code.
 * @ln: line number of error
 * @ln_rd: error line buffer
 * Description: error handerl
 * Return: void
 */

void man_errs(int err_num, char *opc, unsigned int ln, char *ln_rd)
{
	if (err_num >= 100 && err_num < 200)
		mall_errs(err_num, opc, ln);
	else if (err_num >= 200 && err_num <= 210)
		opc_errs(err_num, ln);
	else if (err_num >= 211 && err_num <= 220)
		extra_errs(err_num, ln);
	else
		return;

	set_stack_free();

	if (ln_rd)
		free(ln_rd);

	exit(EXIT_FAILURE);
}

/**
 * mall_errs - errors for malloc handler
 * @err_num: defined error code
 * @opc: operation code
 * @ln: line on which the error occurred.
 * Description: handles all malloc related errors and invalid instructions
 * Return: void
 */

void mall_errs(int err_num, char *opc, unsigned int ln)
{
	switch (err_num)
	{
	case INVALID_ERROR:
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opc);
		break;
	case MALL_ERROR:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	default:
		break;
	}
}

/**
 * opc_errs - manges related errors for opcode operations.
 * @err_num: defined error codes
 * @ln: line on which the error occurred.
 * Description: handles all opcode operations errors
 * Return: void
 */

void opc_errs(int err_num, unsigned int ln)
{
	switch (err_num)
	{
	case USAGE_ERROR:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case PUSH_ERROR:
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		break;
	case PINT_ERROR:
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		break;
	case POP_ERROR:
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		break;
	case SWAP_ERROR:
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		break;
	case ADD_ERROR:
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		break;
	case SUB_ERROR:
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		break;
	case DIV_ERROR:
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		break;
	case ZERO_DIV_ERROR:
		fprintf(stderr, "L%d: division by zero\n", ln);
		break;
	case MULT_ERROR:
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		break;
	case MODL_ERROR:
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		break;
	default:
		break;
	}
}

/**
 * extra_errs - manages errors for pchar operations
 * @err_num: defined error code specifier
 * @ln: line on which the error occurred
 * Description: handles pchar operation errors
 * Return: void
 */
void extra_errs(int err_num, unsigned int ln)
{
	switch (err_num)
	{
	case PCHAR_ERROR_1:
		fprintf(stderr, "L%d: can't pchar_opc, value out of range\n", ln);
		break;
	case PCHAR_ERROR_2:
		fprintf(stderr, "L%d: can't pchar_opc, stack empty\n", ln);
		break;
	default:
		break;
	}
}
