#include "main.h"

/**
 * Append_Text_To_File - it appends a text at the end of file!
 * @filename:  Pointer to name of a file!
 * @text_content : string to add to the end of a file!
 *
 * Return : incase of a failed function or if filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *          return - 1.
 */
int append_text_fo_file(const char *filename, char *text_content)
{
	int NP, GH, GUT = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (GUT = 0; text_content[GUT];)
			GUT++;
	}

	NP = open(filename, O_WRONLY | O_APPEND);
	GH = write(NP, text_content, GUT);

	if (NP == -1 || GH == -1)
		return (-1);

	close(NP);

	return (1);
}
