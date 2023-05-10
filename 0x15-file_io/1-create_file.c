#include "main.h"

/**
 * create_file --- it makes  file!
 * @filename: creates pointer to name of the file it makes!
 * @text_content: creates pointer to  string to write the file!
 *
 * Return: incase of a failed function - -1.
 *         else may return - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int xb, lk, mut = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (mut = 0; text_content[mut];)
			mut++;
	}

	xb = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	lk = write(xb, text_content, mut);

	if (xb == -1 || lk == -1)
		return (-1);

	close(xb);

	return (1);
}	
