#include "monty.h"

/**
 * get_num_args - get the arguments passed on to the interpreter
 * @num_args: number of args
 * Description: gets, and checks the args passed on to the inpertreter
 * Return: void
 */

void get_num_args(int num_args)
{
	if (num_args != MIN_ARGS)
		man_errs(USAGE_ERROR, NULL, 0, NULL);
}

/**
 * get_rd_perm - verifieis if the user has permissions to read the file
 * @file_name: the file
 * Description: gets, and checks if user has permissions
 *				to read the file
 * Return: void
 */

void get_rd_perm(char *file_name)
{
	if (access(file_name, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate_push_data - check the data of the pushed
 * @d: The parameter to be validated.
 * Description: verifies the data of the pushed instruction to be executed
 * Return: 0 if data is valid or errcode if is invalid.
 */
int validate_push_data(char *d)
{
	if (d == NULL || validate_digits(d) == 0)
		return (PUSH_ERROR);

	return (VALID_DATA);
}

/**
 * validate_digits - checks if all charecters in input str are digits
 * @str: The string to be checked.
 * Description: checks if all characters in a string are digits
 * Return: 1 if all if all evaluated characters are digits
 *		excluding dashes, else 0 if not
 */

int validate_digits(char *str)
{
	while (*str != '\0')
	{
		if (str[0] == '-')
		{
			str++;
			continue;
		}

		if (isdigit(*str) == 0)
			return (0);

		str++;
	}

	return (1);
}
