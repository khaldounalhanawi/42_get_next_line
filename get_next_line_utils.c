#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (ch == '\0')
	{
		while (*s != ch)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		len_total;
	char	*p;
	char	*original;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	len_total = len1 + len2 + 1;
	p = malloc (len_total * sizeof(char));
	if (!p)
		return (NULL);
	original = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (original);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*record;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	p = malloc((len + 1) * (size_t) sizeof(char));
	if (!p)
		return (NULL);
	record = p;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (record);
}