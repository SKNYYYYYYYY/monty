#include "monty.h"

#include "monty.h"

/**
 * free_arguments - Frees all allocated memory for the arguments structure.
 *
 * Description: This function checks if the global 'arguments' variable
 * is not NULL. It then frees all allocated memory for the stream, line,
 * tokens, and instructions, and finally frees the 'arguments' structure itself.
 * The global 'arguments' pointer is set to NULL after freeing.
 */
void free_arguments(void)
{
	int i;

	if (arguments != NULL)
	{
		if (arguments->stream != NULL)
			fclose(arguments->stream);

		if (arguments->line != NULL)
			free(arguments->line);

		if (arguments->token != NULL)
		{
			for (i = 0; i < arguments->n_tokens; i++)
			{
				if (arguments->token[i] != NULL)
					free(arguments->token[i]);
			}
			free(arguments->token);
		}

		if (arguments->instruction != NULL)
			free(arguments->instruction);

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
/**
 * free_all - Frees all allocated resources.
 *
 * This function closes the input stream, frees the tokens,
 * and deallocates the arguments used in the program.
 */
void free_all(void)
{
	close_stream();
	free_tokens();
	free_arguments();
}
