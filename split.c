#include "simple_shell.h"

/**
 * _strchr - Locates a character in a string
 * @str: String
 * @c: Character
 * Return: Pointer to the first occurrence of the character
*/
int	_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = _strlen(str);
	while (i < (len + 1))
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * count_words - Counts the number of words in a string
 * @str: String
 * @c: Delimiters
 * Return: Number of words
*/
static size_t	count_words(const char *str, char *c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && _strchr(c, str[i]) >= 0)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && _strchr(c, str[i]) == -1)
			i++;
	}
	return (count);
}

/**
 * _split - Splits a string into words
 * @s: String
 * @c: Delimiters
 * Return: Array of words
*/
char	**_split(char const *s, char *c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	start = 0;
	end = 0;
	i = -1;
	while (++i < count_words(s, c))
	{
		while (_strchr(c, s[start]) >= 0)
			start++;
		end = start;
		while (_strchr(c, s[end]) == -1 && s[end])
			end++;
		split[i] = _substr(s, start, (end - start));
		start = end;
	}
	split[i] = 0;
	return (split);
}
