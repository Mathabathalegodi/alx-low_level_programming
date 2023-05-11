#include "main.h"

/**
 * append_text_to_file - it appends a text at the end of file!
 * @fILeNamES:  Pointer to name of a file!
 * @tExT_cOnTeNtS : string to add to the end of a file!
 *
 * Return : incase of a failed function or if filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *          return 1.
 */
int append_text_to_file(const char *fILeNamES, char *tExT_cOnTeNtS)
{
	int NP, GH, GUT = 0;

	if (fILeNamES == NULL)
		return (-1);

	if (tExT_cOnTeNtS != NULL)
	{
		for (GUT = 0; tExT_cOnTeNtS[GUT];)
			GUT++;
	}

	NP = open(fILeNamES, O_WRONLY | O_APPEND);
	GH = write(NP, tExT_cOnTeNtS, GUT);

	if (NP == -1 || GH == -1)
		return (-1);

	close(NP);

	return (1);
}
