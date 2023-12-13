#include "simple_shell.h"

/**
 * _strjoin - Gets an environment variable
 * s1: Name of the variable
 * s2: Environment
 * Return: Pointer to the variable, NULL if not found
*/
char	*_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[s1_len++] = s2[i++];
	}
	str[s1_len] = '\0';
	return (str);
}
