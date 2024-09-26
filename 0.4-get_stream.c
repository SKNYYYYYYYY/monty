#include "monty.h"

/**
 * get_stream - Opens a file and sets up a stream for reading
 * @filename: Name of the file to open
 */
void get_stream(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		free_arguments();
		exit(EXIT_FAILURE);
	}

	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		dprintf(2, "Error: Can't open file %s\n", filename);
		free_arguments();
		exit(EXIT_FAILURE);
	}
}
