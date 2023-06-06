#include "monty.h"

/**
 * get_opcode_token - gets opcode token from a given string
 *                    starting from a given index
 * @str: string
 * @token: pointer where the new token is going to be stored
 * @idx: start index
 *
 * Return:  1 if successful,
 *          0 there is no token left to parse
 *         -1 if malloc error happened
 */
short get_opcode_token(char *str, char **token, unsigned int *idx)
{
	int i, token_len = 0;
	char *delim = EMPTY_DELIMS, *result = NULL;

	*token = NULL;
	skip_delimiter(str, idx, delim);
	token_len = get_token_len(str, *idx, delim);
	if (token_len == 0)
		return (0);
	/* +1 for null byte */
	result = malloc(token_len + 1);
	if (result == NULL)
		return (-1);
	for (i = 0; token_len > 0; i++)
	{
		result[i] = str[*idx];
		(*idx)++;
		token_len--;
	}
	result[i] = '\0';
	*token = result;
	return (1);
}

/**
 * is_delim - checks if a character is in a delimiter
 * @ch: character to check
 * @delim: string of a delimeters
 *
 * Return: 1 if it exists, 0 otherwise
 */
short is_delim(char ch, char *delim)
{
	int idx;

	for (idx = 0; delim && delim[idx]; idx++)
	{
		if (delim[idx] == ch)
			return (1);
	}
	return (0);
}

/**
 * skip_delimiter - skips the delimiter from a given string
 *                  starting from a given index till it gets
 *                  non-delimiter
 * @str: string
 * @idx: start index
 * @delim: token delimiter
 */
void skip_delimiter(char *str, unsigned int *idx, char *delim)
{
	while (str && str[*idx] && is_delim(str[*idx], delim))
		(*idx)++;
}

/**
 * get_token_len - gets the token length starting
 *                 from the given index till it gets
 *                 delimiter
 * @str: string
 * @idx: start index
 * @delim: token delimiter
 *
 * Return: Length of the token
 */
short get_token_len(char *str, unsigned int idx, char *delim)
{
	unsigned int token_len = 0;

	while (str && str[idx] && !is_delim(str[idx], delim))
	{
		idx++;
		token_len++;
	}
	return (token_len);
}
