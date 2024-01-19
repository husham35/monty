#include "monty.h"

/**
 * open_file - opens a file
 * @file_name: file to open.
 * Description: opens a file to read the commands in it and execute it
 * Return: fd of the opened file
 */
FILE *open_file(char *file_name)
{
	FILE *fd = NULL;

	get_rd_perm(file_name);

	fd = fopen(file_name, "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
