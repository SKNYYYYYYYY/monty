#include "monty.h"

/**
 * free_arguments - Frees memory allocated for arguments
 */
void free_arguments(void)
{
	if (arguments != NULL)
	{
		if (arguments->stream != NULL)
			fclose(arguments->stream);
		if (arguments->line != NULL)
			free(arguments->line);
		free(arguments);
		arguments = NULL;
	}
}

/**
 * malloc_failed - Handles malloc failure
 */
void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}
