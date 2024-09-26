#include "main.h"

/**
 * tokenize_line - Tokenizes the input line
 */
void tokenize_line(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *line_cpy = NULL, *saveptr;

	line_cpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	if (line_cpy == NULL)
		malloc_failed();
	strcpy(line_cpy, arguments->line);

	arguments->n_tokens = 0;
	token = strtok_r(line_cpy, delims, &saveptr);
	while (token != NULL)
	{
		arguments->n_tokens++;
		token = strtok_r(NULL, delims, &saveptr);
	}

	arguments->token = malloc(sizeof(char *) * (arguments->n_tokens + 1));
	if (arguments->token == NULL)
	{
		free(line_cpy);
		malloc_failed();
	}
	strcpy(line_cpy, arguments->line);
	token = strtok_r(line_cpy, delims, &saveptr);
	while (token != NULL)
	{
		arguments->token[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (arguments->token[i] == NULL)
		{
			free_tokens();
			malloc_failed();
		}
		strcpy(arguments->token[i], token);
		token = strtok_r(NULL, delims, &saveptr);
		i++;
	}
	arguments->token[i] = NULL;
	free(line_cpy);
}
