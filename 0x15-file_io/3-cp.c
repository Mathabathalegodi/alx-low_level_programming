#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_matter(char *file);
void close_file(int rgt);

/**
 * create_buffer - Allocates 1024 bytes for matter!
 * @file:  name of the file matter is storing chars for!
 *
 * Return: A pointer to newly-allocated matter!
 */
char *create_matter(char *file)
{
	char *matter;

	matter = malloc(sizeof(char) * 1024);

	if (matter == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (matter);
}

/**
 * close_file - it will close the file descriptors!
 * @fd: it is file descriptor to be closed!
 */
void close_file(int rgt)
{
	int wr;

	wr = close(rgt);

	if (wr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", rgt);
		exit(100);
	}
}

/**
 * main - it will copy the contents of a file to another file!
 * @argc : it is number of arguments supplied to the program!
 * @argv : it is array of pointers to arguments!
 *
 * Return: 0 if successful!
 *
 * Description :if an argument count is not correct - exit code 97.
 * if file_gap doesn't exist or can't be found - exit code 98.
 * if file_op cannot be formed or written out to - exit code 99.
 * if file_op or file_gap can't be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int gap, op, Ms, Yr;
	char *matter;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	matter = create_matter(argv[2]);
	gap = open(argv[1], O_RDONLY);
	Ms = read(gap, matter, 1024);
	op = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (gap == -1 || Ms == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(matter);
			exit(98);
		}

		Yr = write(op, matter, Ms);
		if (op == -1 || Yr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(matter);
			exit(99);
		}

		Ms = read(gap, matter, 1024);
		op = open(argv[2], O_WRONLY | O_APPEND);

	} while (Ms > 0);

	free(matter);
	close_file(gap);
	close_file(op);

	return (0);
}
