#include "simple_shell.h"

/**
 * count_words - Counts the number of words in a string
 * @str: String to count words from
 * @c: Delimiter
 * Return: Number of words
*/
static	size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

/**
 * split - Splits a string into words
 * @s: String to split
 * @c: Delimiter
 * Return: Pointer to array of words
*/
char	**_split(char const *s, char c)
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
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = _substr(s, start, (end - start));
		start = end;
	}
	split[i] = 0;
	return (split);
}
