#include "simple_shell.h"

char	*_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			slen;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	slen = _strlen(s);
	i = 0;
	if (!len || !slen || start >= slen)
	{
		dst = (char *)malloc(sizeof(char));
		dst[0] = '\0';
		return (dst);
	}
	while (i < len && s[i + start] != '\0')
		i++;
	dst = (char *)malloc((i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
		dst[j++] = s[start++];
	dst[j] = '\0';
	return (dst);
}