#include "main.h"
#include <stdlib.h>

/**
 * Read_textfile - it reads the text file print to STDOUT!
 * @filename : Text file that is been read!
 * @letters :the number of letters that is to be read!
 * Return: HR -The actual number of bytes read and printed out!
 *        0 When ever the function fails or filename is NULL!
 */
ssize_t read_textfile(const char *filename, size_t letters)

{
	char *buT;
	ssize_t xr;
	ssize_t HR;
	ssize_t KM;

	xr = open(filename, O_RDONLY);
	if (xr == -1)
		return (0);
	buT = malloc(sizeof(char) * letters);
	KM = read(xr, buT, letters);
	HR = write(STDOUT_FILENO, buT, KM);

	free(buT);
	close(xr);
	return (HR);
}
